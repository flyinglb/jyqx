// whisper.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg;
	object ob;
        
        if((time() - (int)me->query_temp("last_whisper_time") < 5) && !wizardp(me)){
                write("��˵��̫���ˣ��������������\n");
                return 1;
        }

        seteuid(getuid());
        
	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("��Ҫ��˭����Щʲô��\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("��Ҫ��˭���\n");

	write( HIW + "��" +NOR+WHT+ "��" +HIY+ ob->name() + NOR+MAG+ "�Ķ�������˵����" + HIY + msg + "\n" + NOR);
	tell_room( environment(me), me->name() + "��" + ob->name()
		+ "����С����˵��Щ����\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, HIW + me->name() +NOR+WHT+ "��" +HIY+ "��" +NOR+MAG+ "�Ķ�������˵����" + HIY + msg + "\n" NOR);
        if( !userp(me) || !(int)me->query("channel_snooping") ) return 1;

message("channel:snp", HIB"��������"HIW+me->query("name")+"("+me->query("id")+")"+NOR+MAG+"���ĸ���"+HIY+ob->query("name")+"("+ob->query("id")+")��"+msg+"\n"NOR, users());
        me->set_temp("last_whisper_time",time());
	return 1;
}

int help(object me)
{
	write( @TEXT
ָ���ʽ��whisper <ĳ��> <ѶϢ>

���ָ�����������ͬһ�����е��˶������ NPC ���ڡ�
TEXT
	);
	return 1;
}
