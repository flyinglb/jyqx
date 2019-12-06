// tell.c

#include <ansi.h>
#include <net/dns.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;

        if((time() - (int)me->query_temp("last_tell_time") < 4) && !wizardp(me)){
                write("��˵��̫���ˣ��������������\n");
                return 1;
        }

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

      if( sscanf(target, "%s@%s", target, mud)==2 ) {
              GTELL->send_gtell(mud, target, me, msg);
              write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
              return 1;
      }

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
        if( obj == me ) return notify_fail("�����˭˵����\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="all")
		return notify_fail("����˲����������¡�\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="ALL")
		return notify_fail("����˲����������¡�\n");
	if (!wizardp(me) && obj->query("env/no_tell")==me->query("id"))
		return notify_fail("����˲����������¡�\n");
	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("���ڹ���������������Ļ�������\n");

	write(HIG "�����" + obj->name(1) + "��" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIG "%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));
        if( !userp(me) || !(int)me->query("channel_snooping") ) return 1;

message("channel:snp", HIB"��������"+HIG+me->query("name")+"("+me->query("id")+")"+HIW+"����"+HIG+obj->query("name")+"("+obj->query("id")+")��"+msg+"\n"NOR, users());

        me->set_temp("last_tell_time",time());
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)�����㣺%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s �����㣺%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵����

�������ָ�reply
HELP
	);
	return 1;
}
