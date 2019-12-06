// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object where = environment(me);
	string skillname;
	int skill, skill_basic, times, pertimes;

	seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("ָ���ʽ��practice|lian <��������> <����>\n");

	if ( times < 1 || times > 30)
		return notify_fail("��ϰ�����������һ�Σ������ܳ�����ʮ�Ρ�\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);
	if( skill < 1 )
		return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
	if( skill_basic < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	notify_fail("�����ڲ�����ϰ����ܡ�\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
	{
		return notify_fail("Ҳ����ȱ��ʵս���飬�����ϰ��û��������\n");
		return 1;
	}

	write( HIC "�����Ű�" + to_chinese(skillname) + "����"+chinese_number(times)+"�ˡ�\n" NOR);
	for (pertimes = 1; pertimes <= times; pertimes ++)
	{
		if( SKILL_D(skillname)->practice_skill(me) )
			me->improve_skill(skillname, (skill_basic/5 +1), skill_basic > skill? 0: 1);
		else return 0;
	}
	write( HIY "���" + to_chinese(skillname) + "�����ˣ�\n" NOR);
//	me->start_busy(1);
	return 1;
}

int help(object me)
{
	write(@TEXT
ָ���ʽ��practice|lian <��������> <����>

���ָ��������ϰĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�

�������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
TEXT
	);
	return 1;
}
