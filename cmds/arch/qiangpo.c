// qiangpo.c

#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, cmd, str;
	object ob;

	if( me != this_player() ) return 0;

	me = this_player();

	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("ָ���ʽ: qiangpo <ĳ��> to <ָ��>\n");
	
	if( !objectp(ob = present(dest, environment(me))))
		return notify_fail("�Ҳ���" + dest + "��\n");
 
	if( !living(ob) )
		return notify_fail("����������ִ�����\n");
		
        if( wiz_level(me) <= wiz_level(ob) && userp(ob) ) {
		str = HIR+me->name()+"("+me->query("id")+")"+"��ͼǿ����ִ�� "+cmd+" ���\n"+NOR ;
		tell_object(ob, str);
		return notify_fail("��û��ǿ��" + ob->name() + "ִ��ָ���Ȩ����\n");
	}
	
	if( userp(ob) )
		log_file("force_player", sprintf("[%s] %s forces %s to %s\n",  
			ctime(time()), geteuid(me), geteuid(ob), cmd));
	return ob->force_me(cmd);
}

int help(object me)
{
	write(@Help
 ָ���ʽ: qiangpo <ĳ��> to <ָ��>

 ǿ��ĳ����ĳ��, �������ʦ�ȼ�����ȶԷ��ߡ�
Help
	);
	return 1;
}
