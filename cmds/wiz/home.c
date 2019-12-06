// home.c

#include "/doc/help.h"
#include  <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg,file1,file2,str;
	object ob;
	file1="/clone/misc/wizroom.c";
	seteuid("Root");
	if(!arg || arg == geteuid(me)) {
	file2="/u/"+geteuid(me)+"/workroom.c";
	arg = 0;
	}
	else {
		ob = new(LOGIN_OB);
		ob->set("id",arg);
		if( !ob->restore() ) return notify_fail( "û�������ҡ�\n");
		file2="/u/"+arg+"/workroom.c";
	     }

	if(file_size(file2) <=0)
	{
		if(arg) return notify_fail(ob->query("name")+"û���Լ��Ĺ����ҡ�\n");
		else if( !get_dir("/u/"+geteuid(me)+"/")  )
	{
	if(mkdir("/u/"+geteuid(me)))
	write(GRN "\n���Ŀ¼���� /u �¡�\n\n" NOR);
	else return notify_fail("����Ŀ¼ʧ�ܣ�\n");
	}
	str=read_file(file1);
	str = replace_string(str,"NAME",this_player()->name());
	write_file(file2,str);
	}
	if(arg) message_vision("$Nȥ"+ob->query("name")+"�������ˡ�\n",me);
	else if( stringp(msg = me->query("env/msg_home")) )
            message_vision(msg + "\n", me);
	else if ( me->query("env/no_msg") )
        message_vision("", me);
	else message_vision("$N�ؼ�ȥ�ˡ�\n",me);
	me->move(file2);
	if(arg) message_vision("$N��"+ob->query("name")+"���������ˡ�\n",me);
	else if( stringp(msg = me->query("env/msg_home")) )
            message_vision(msg + "\n", me);
	else if ( me->query("env/no_msg") )
        message_vision("", me);
	else message_vision("$N�ؼ����ˡ�\n",me);
return 1;
}

int help(object me)
{
 write(@HELP
ָ���ʽ : home �� home <sb>

���ô�һָ���ֱ�ӻص��Լ��Ĺ����һ��й����ҵ���ʦ�����͡�
������� 'msg_home' ����趨, ���ڳ����˶��ῴ���Ǹ�ѶϢ.
HELP
    );
    return 1;
}
