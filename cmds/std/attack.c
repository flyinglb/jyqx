// attack.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, *inv;
	int cost, i = 0;

	seteuid(getuid());

	if(environment(me)->query("no_fight"))
		return notify_fail("���ﲻ��򶷣�\n");
	if ( me->query_skill("training",1) < 30 )
		return notify_fail("���Ԧ�����������죬�޷���Ұ�ް���ҧ�ˣ�\n");
	cost = me->query("max_jing")/(me->query_skill("training",1)/10) - 10;
	if ( me->query("jing") <= cost )
		return notify_fail("������̫���ˣ��޷���Ұ�ް���ҧ�ˡ�\n");
	if ( !arg )
		return notify_fail("��Ҫ��ʲôҰ�ް���ҧ˭��\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("����û����������ɣ�\n");

	inv = all_inventory(environment(me));
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("owner") == me->query("id") )
		{
			if( inv[i]->is_fighting() )
				return notify_fail("�Ѿ���Ұ���ڰ���ҧ���ˣ�\n");
			if( inv[i]->is_busy() )
				return notify_fail(inv[i]->name() + "����æ����û�����㣡\n");
			if( (ob->query("age")< 16 ) && userp(ob))
				return notify_fail(ob->query("name")+"���Ǹ�С���ӣ����˰�...����\n");
message_vision("ֻ��$N����"+inv[i]->name()+"����һ�����ڣ���һ�ܾ���$n������ȥ��\n\n",me,ob);
			me->receive_damage("jing", cost);
			inv[i]->fight_ob(ob);
			return 1;
		}
		i++;
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : attack <����>

��ָ���������ĳ������㹥����ҧ���ˡ������Ѿ�ѱ���Ķ�����Խ���
����ָ�

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
