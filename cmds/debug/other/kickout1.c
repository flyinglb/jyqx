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
        if( !arg ) return notify_fail("指令格式 : kickout <id> because <why>。\n" );

        if( sscanf(arg, "-h %s", arg) ) DisableMsg = 1;

        if( sscanf(arg, "%s because %s", arg, reason) < 1 )
                return notify_fail("指令格式 : kickout <id> because <why>。\n" );

        seteuid(ROOT_UID);

        obj = find_player(arg);
        if( !objectp(obj) )    obj = present(arg, environment(me));

        if( !obj || !userp(obj) ) return notify_fail("没有这个玩家....。\n");
        name = obj->short(1);
        q_name = obj->name();
        q_id = obj->query("id");
        q_ip = query_ip_name(obj);

        if( me == obj )
                return notify_fail("用quit这条指令好些:) 。\n");

        if( (wiz_level(me) < wiz_level(obj)) || (wiz_level(me) == wiz_level(obj)) )
                if( wiz_level(me) != wiz_level("(admin)") )
                        return notify_fail("反了，反了，你想革命吗？？？\n");
        message_vision(HIR "\n突然天空中伸出一只"HIW"大脚"HIR"，一脚狠狠的把$N"HIR"踢出了"+MUD_NAME+"。\n\n" NOR, obj);
        obj->save();
        catch(destruct(obj));
        if( obj ) return notify_fail("你无法让这个玩家离线。\n");
        else {
                set("channel_id", "大脚板(KickOut)");
                if( !DisableMsg)
                        CHANNEL_D->do_channel(this_object(), "rumor", q_name + "被系统踢出了"+MUD_NAME+"。");
                CHANNEL_D->do_channel(this_object(), "sys",sprintf("%s(%s)被%s(%s)踢出了%s。",
                        q_name,q_id,me->query("name"),me->query("id"),MUD_NAME));

log_file("kickout",
                sprintf("%s(%s) kickout %s(%s) because (%s) on at %s.\n", me->name(), 
                        me->query("id"), q_name, q_id, reason, q_ip, ctime(time()) ) );
                write("哼。。。终于出了这口恶气！\n");
        }
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : kickout -h <id> because <reason>

此命令可以强迫恶意的玩家离线，请先再三考虑，慎用此命令。
如果加上 -h 则不显示 rumor channel 的信息。

HELP );
        return 1;
}

