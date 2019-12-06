// ting.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
	object ob;

	seteuid(getuid());

	if ( !me->query_temp("comedby"))
		return notify_fail("�Ѿ�û��Ұ�޸������ˣ�\n");
	if( me->is_fighting() )
		return notify_fail("һ�ߴ��һ��ѱ�ޣ������ǻ����ˣ�\n");
	if( !objectp(ob = present(me->query_temp("comedby"), environment(me)) ))
		return notify_fail("����û����ֻҰ�ްɣ�\n");
        if( !ob->query_temp("owner") )
                return notify_fail(ob->name() + "��ֻ����Ұ�ޣ������ѱ��(train)������\n");
        if( ob->query_temp("owner") &&
           ( ob->query_temp("owner") != me->query("id") ))
	{
		ob->kill_ob(me);
                return notify_fail(ob->name() + "�Ǳ��˼�ѱ���ˣ��㲻����������\n");
	}
	if ( ob == me )
		return notify_fail("��û����ɣ��Լ����Լ���\n");
	if (!living(ob)) 
		return notify_fail("��ֻҰ���ε��ˣ����������������أ�\n");
	if (ob->is_fighting()) 
		return notify_fail("�����ڴ����֣�û�������أ�\n");

	message_vision("ֻ��$N����"+ob->name()+"���а��˸���ʽ������������˵�ͷ��\n\n",me);

	me->delete_temp("comedby");
	ob->set_leader(0);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : stay <����>

��ָ���������ĳ����ֹͣ�����㡣�����Ѿ�ѱ���Ķ�����Խ�������ָ�

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

