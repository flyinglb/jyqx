// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;

        if((time() - (int)me->query_temp("last_tell_time") < 3) && !wizardp(me)){
                write("��˵��̫���ˣ��������������\n");
                return 1;
        }

	if( !arg || arg=="" )
		return notify_fail("��Ҫ�ش�ʲô��\n");
	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("�ղ�û���˺���˵������\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("�ղź���˵�����������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
/*
	if (!wizardp(me) && obj->query("env/no_tell")=="all")
		return notify_fail("����˲���������������\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="ALL")
		return notify_fail("����˲���������������\n");
	if (!wizardp(me) && obj->query("env/no_tell")==me->query("id"))
		return notify_fail("����˲���������������\n");
*/
	write(HIM "��ش�" + obj->name(1) + "��" + arg + "\n" NOR);
	tell_object(obj, sprintf(HIM"%s�ش��㣺%s\n"NOR,
		me->name(1)+"("+me->query("id")+")", arg));
        
        if( !userp(me) || !(int)me->query("channel_snooping") ) return 1;

message("channel:snp", HIB"��������"+HIG+me->query("name")+"("+me->query("id")+")"+HIM+"�ش�"+HIG+obj->query("name")+"("+obj->query("id")+")��"+arg+"\n"NOR, users());
        me->set_temp("last_tell_time",time());
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��reply <ѶϢ>

����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell
HELP
	);
	return 1;
}
