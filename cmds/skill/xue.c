// learn.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"˵������̫�����ˣ�����ô�ҵ���\n",
	"�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
	"Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
//        string skill, teacher, master, skill_name;
        string skill, teacher, skill_name;
	object ob;
	int master_skill, my_skill, jing_cost, times, pertimes;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	//if(!arg || (sscanf(arg, "%s %s %d", teacher, skill, times)!=3 ))
		//return notify_fail("ָ���ʽ��learn|xue <ĳ��> <����> <����>\n");
        if( (!arg || ((sscanf(arg, "%s %s %d", teacher, skill, times) !=3 ))
        && (sscanf(arg, "%s %s", teacher, skill) !=2 )) )
                return notify_fail("ָ���ʽ��learn|xue <ĳ��> <����> <����>\n");
                
        if(!times) times = 1;

	if (times < 1 || times > 100)
		return notify_fail("ѧϰ��������һ�Σ����Ҳ���ܳ���һ�ٴΡ�\n");

	if( me->is_fighting() )
		return notify_fail("����ĥǹ������������\n");

// 	if( !(ob = present(teacher, environment(me))) || !ob->is_character() )
        if( !(ob = present(teacher, environment(me))) || !ob->is_character() || !me->visible(ob) )
		return notify_fail("��Ҫ��˭��̣�\n");

	if( !living(ob) )
		return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

	if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) ) {
//		if( (string)me->query("family/family_name") != (string)ob->query("family/family_name")
//		||	(int)ob->query("family/privs") != -1 ) {
		return	notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
//			if( !(ob->recognize_apprentice(me)) ) return 0;
//		}
	}

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("���������±����ұ���ѧ�ˡ�\n");

	notify_fail(ob->name() + "��Ը���������ܡ�\n");
	if( ob->prevent_learn(me, skill) )
		return 0;

	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");

	if( my_skill >= (int)(master_skill - me->query("betrayer")*2))
		return notify_fail(ob->name() + "������üͷ�������������ȥ����ʦ������\n");

	notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	jing_cost = 150 / (int)me->query("int");
	if( !my_skill ) {
		jing_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("���Ǳ�ܲ���ѧϰ��ô����ˡ�\n");
	printf(HIC"����%s�����"+chinese_number(times)+"���йء�%s�������ʡ�\n"NOR, ob->name(), to_chinese(skill));

	if( ob->query("env/no_teach") )
		return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");

	tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",
		me->name(), to_chinese(skill)));

	if( (int)ob->query("jing") > jing_cost*times/5 + 1 )
	{
		if( userp(ob) ) ob->receive_damage("jing", jing_cost/5 + 1);
	} else
	{
		write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲ�ᡣ\n");
		tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + "��\n");
		return 1;
	}
		
	if( (int)me->query("jing") > jing_cost * times )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		{
			return notify_fail("Ҳ����ȱ��ʵս���飬���"+ob->name()+"�Ļش������޷���ᡣ\n");
		} else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
	 			printf("������%s��ָ�����ԡ�%s����һ���ƺ���Щ�ĵá�\n", ob->name(),
					skill_name);
			else
				printf("������%s��ָ�����ƺ���Щ�ĵá�\n", ob->name());
			for (pertimes = 1; pertimes <= times ; pertimes ++)
			{
				me->add("learned_points", 1);
				me->improve_skill(skill, random(me->query_int()));
			}
		}
	} else
	{
		if (jing_cost > me->query("jing"))
			jing_cost = me->query("jing");
		return notify_fail("�����̫���ˣ����ʲôҲû��ѧ����\n");
	}
	me->receive_damage("jing", jing_cost * times );
//	me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : learn|xue <ĳ��> <����> <����>
           learn|xue <ĳ��> <����>
 
���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ��������û��ָ��������Ĭ��Ϊһ�Ρ�

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�

�������ָ�� : apprentice, practice, skills, study
HELP
        );
        return 1;
}
