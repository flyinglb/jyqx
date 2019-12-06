// come.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	int cost;

	seteuid(getuid());

	if( me->is_fighting() )
		return notify_fail("һ�ߴ��һ��ѱ�ޣ������ǻ����ˣ�\n");
	if ( me->query_skill("training",1) < 10 )
		return notify_fail("���Ԧ�����������죬�޷���Ұ�޸����㣡\n");
	if ( me->query_temp("comedby"))
		return notify_fail("�Ѿ���Ұ�޸������ˣ�\n");
	if ( !arg )
		return notify_fail("��Ҫ��ʲôҰ�޸����㣿\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("����û����ֻҰ�ްɣ�\n");
	if (userp(ob)) 
		return notify_fail("�˼�Ҳ����ң����ʲô�㰡��\n");
	if (ob->query("race") != "Ұ��") 
		return notify_fail("�ⲻ��Ұ�ޣ�����ͷ�˰ɣ�\n");
        if( ob->is_fighting() )
                return notify_fail(ob->name() + "���ڴ�ܣ�û�����㣡\n");
        if( ob->is_busy() )
                return notify_fail(ob->name() + "����æ����û�����㣡\n");
        if( !ob->query_temp("owner") )
                return notify_fail(ob->name() + "��ֻ����Ұ�ޣ������ѱ��(train)������\n");
        if( ob->query_temp("owner") &&
           ( ob->query_temp("owner") != me->query("id") ))
	{
		ob->kill_ob(me);
                return notify_fail(ob->name() + "�类�˼�ѱ���ˣ��㲻����������\n");
	}
	if ( ob == me )
		return notify_fail("��û����ɣ��Լ����Լ���\n");
	if (!living(ob)) 
		return notify_fail("��ֻҰ���ε��ˣ����������������أ�\n");

	cost = me->query("max_jing")/(me->query_skill("training",1)/10) - 10;

	if ( me->query("jing") <= cost )
		return notify_fail("������̫���ˣ��޷���Ұ�޸��档\n");

	message_vision("ֻ��$N����"+ob->name()+"���а��˸���ʽ����һ�ܾ͸����ˡ�\n\n",me);

	me->receive_damage("jing", cost );
	me->set_temp("comedby", ob->query("id"));
	ob->set_leader(me);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : come <����>

��ָ���������ĳ��������㡣�����Ѿ�ѱ���Ķ�����Խ�������ָ�

����ָ�
        come <������>:                  �ö�����������ж���
        stay:                           ֹͣ����ĸ���״̬��
        attack <ĳ��>:                  �ö��﹥�����ˡ�
        stop <������>:                  �ö���ֹͣ���˵Ĺ�����
        release:                        ������ū״̬����������롣

����ָ���ֻ��ĳЩ�������ã�
        qi(ride) <������>:              ���������������ȡ�
        xia(unride) <������>:           �£��뿪���
        wei(feed) <������>:             �涯��ιʳ��
        yin <������>:                   ��������ˮ��

HELP
	);
	return 1;
}

