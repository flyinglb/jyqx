// research.c(yanjiu.c)

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, skill_name;
        object where = environment(me);
	int my_skill, jing_cost, times, pertimes;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (!where->query("sleep_room"))
             return notify_fail("����̫���ӣ���û�����о���\n");

	//if(!arg || (sscanf(arg, "%s %d", skill, times)!=2 ))
		//return notify_fail("ָ���ʽ��research|yanjiu <����> <����>\n");
        if(!arg || (sscanf(arg, "%s %d", skill, times)!=2 )) {
                times = 1; skill = arg;
        }
        
	if (times < 1 || times > 100)
		return notify_fail("�о���������һ�Σ����Ҳ���ܳ���һ�ٴΡ�\n");

	if( me->is_fighting() )
		return notify_fail("����ĥǹ������������\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("����������û���о��ˡ�\n");

	if( (string)SKILL_D(skill)->type()=="knowledge")
		return notify_fail(to_chinese(skill)+"ֻ�ܿ���ѧϰ������ߵġ�\n");

	notify_fail("����Ŀǰ��������û�а취�о����ּ��ܡ�\n");
	if( !SKILL_D(skill)->valid_learn(me) && my_skill < 200) return 0;

	jing_cost = 300 / (int)me->query("int");
	if( !my_skill ) {
		jing_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("���Ǳ�ܲ����о���ô����ˡ�\n");
	printf(HIM"���о���"+chinese_number(times)+"���йء�%s�������ʡ�\n"NOR, to_chinese(skill));

	my_skill = me->query_skill(skill, 1);

	if( (int)me->query("jing") > jing_cost * times )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		{
			return notify_fail("Ҳ����ȱ��ʵս���飬��û���о�"+to_chinese(skill)+"�������ˡ�\n");
		} else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
			printf("���о���һ�ᣬ�ԡ�%s����һ���ƺ���ͨ��Щʲô��\n", skill_name);
			else
			printf("���о���һ�ᣬ�ƺ���"+to_chinese(skill)+"��Щ�µ�����\n");
			for (pertimes = 1; pertimes <= times ; pertimes ++)
			{
				me->add("learned_points", 1);
				me->improve_skill(skill, random((int)me->query_int()/2));
			}
		}
	} else
	{
		jing_cost = me->query("jing");
		return notify_fail("�����̫���ˣ����ʲôҲû���о��ɡ�\n");
	}
	me->receive_damage("jing", times * jing_cost );
//	me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : research | yanjiu <����> <����>
           research | yanjiu <����>
 
���ָ����������о�һ�ּ��ܵ��������⣬����ʦ������ܵļ�
�������ʱ�򣬿���ͨ���о��Լ�����ߣ���Ȼ�������ٶ��ǲ���
��ʦ��ѧ���ˡ����û��ָ��������Ĭ��Ϊһ�Ρ�

�����о�Ҳ��Ҫ����һЩ�����������ĵľ��������Լ��������йء�

�������ָ�� : apprentice, practice, skills, study, learn
HELP
        );
        return 1;
}
