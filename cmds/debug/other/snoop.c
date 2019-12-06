// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("���������ڼ���" + ob->query("name") + "���յ���ѶϢ��\n");
		return 1;
	} else if( arg=="none" ) {
//		if( objectp(ob = query_snooping(me))
//		&&	wiz_level(ob) > wiz_level(me) )
//			tell_object(ob, HIW + me->name(1) + "ֹͣ���������յ���ѶϢ��\n" NOR);
		snoop(me);
		write("Ok.\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");

	if( wizhood(me) != "(admin)"
	&&	wiz_level(me) <= wiz_level(ob) )
		return notify_fail("��û�м���" + ob->name() + "������ѶϢ��Ȩ����\n");

	if( me==ob ) return notify_fail("���� snoop none ���������\n");
		
	snoop(me, ob);
	write("�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n");
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
//	if( wizardp(ob) && wizhood(me) != "(admin)")
//		tell_object(ob, HIW + me->name(1) + "��ʼ���������յ���ѶϢ��\n" + NOR);

	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��snoop <ĳ��>|none

��������ʹ������������ѶϢ��snoop none ��ȡ��������
TEXT
	);
	return 1;
}
