// kickout.c
//by yongqi@jyqxz
#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

int main(object me, string arg)
{
        object obj;
        int DisableMsg;
        string name,q_name,q_id,q_ip,reason;

        DisableMsg = 0;
        if( !arg ) return notify_fail("ָ���ʽ : kickout <id> because <why>��\n" );

        if( sscanf(arg, "-h %s", arg) ) DisableMsg = 1;

        if( sscanf(arg, "%s because %s", arg, reason) < 1 )
                return notify_fail("ָ���ʽ : kickout <id> because <why>��\n" );

        seteuid(ROOT_UID);

        obj = find_player(arg);
        if( !objectp(obj) )    obj = present(arg, environment(me));

        if( !obj || !userp(obj) ) return notify_fail("û��������....��\n");
        name = obj->short(1);
        q_name = obj->name();
        q_id = obj->query("id");
        q_ip = query_ip_name(obj);

        if( me == obj )
                return notify_fail("��quit����ָ���Щ:) ��\n");

        if( (wiz_level(me) < wiz_level(obj)) || (wiz_level(me) == wiz_level(obj)) )
                if( wiz_level(me) != wiz_level("(admin)") )
                        return notify_fail("���ˣ����ˣ���������𣿣���\n");
        message_vision(HIR "\nͻȻ��������һֻ"HIW"���"HIR"��һ�źݺݵİ�$N"HIR"�߳���"+MUD_NAME+"��\n\n" NOR, obj);
        obj->save();
        catch(destruct(obj));
        if( obj ) return notify_fail("���޷������������ߡ�\n");
        else {
                set("channel_id", "��Ű�(KickOut)");
                if( !DisableMsg)
                        CHANNEL_D->do_channel(this_object(), "rumor", q_name + "��ϵͳ�߳���"+MUD_NAME+"��");
                CHANNEL_D->do_channel(this_object(), "sys",sprintf("%s(%s)��%s(%s)�߳���%s��",
                        q_name,q_id,me->query("name"),me->query("id"),MUD_NAME));

log_file("kickout",
                sprintf("%s(%s) kickout %s(%s) because (%s) on at %s.\n", me->name(), 
                        me->query("id"), q_name, q_id, reason, q_ip, ctime(time()) ) );
                write("�ߡ��������ڳ�����ڶ�����\n");
        }
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : kickout -h <id> because <reason>

���������ǿ�ȶ����������ߣ������������ǣ����ô����
������� -h ����ʾ rumor channel ����Ϣ��

HELP );
        return 1;
}

