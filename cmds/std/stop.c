// stop.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
//        int cost, i = 0;


	if ( !arg )
		return notify_fail("��Ҫ��ʲôҰ��ֹͣҧ�ˣ�\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("����û�����Ұ�ްɣ�\n");
	if( ob->query_temp("owner") != me->query("id") )
		return notify_fail("�㲻���������ˣ������������㣡\n");
	if( ob->is_busy() )
		return notify_fail(ob->name() + "����æ����û�����㣡\n");
        message_vision("ֻ��$N����$n����һ�����ڣ�$n���һ�ܣ���ҧ�ˣ�\n\n",me,ob);
        seteuid(getuid());
	ob->remove_all_enemy();
        seteuid(getuid(me));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : stop <����>

��ָ��������ð���ҧ�˵Ķ���ֹͣ������
�����Ѿ�ѱ���Ķ�����Խ�������ָ�

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
