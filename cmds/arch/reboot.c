// reboot.c

#include <login.h>
#include <mudlib.h>

string wiz_name,wiz_id;
protected void do_shutdown()
{
        shutdown(0);
}

int main(object me, string arg)
{
        string wiz_status;
        me = this_player () ;

        if( me != this_player(1) ) return 0;
        
        wiz_status = wizhood(me);
        if(query_wiz_level(wiz_status) < query_wiz_level("(arch)"))
                return notify_fail("只有 (arch) 以上的巫师才能重新启动" + CHINESE_MUD_NAME + "\n");
        if(arg == "none") {
                remove_call_out("countdown");
                message("system",HIY"【"+CHINESE_MUD_NAME+"】重新启动因故取消！\n"NOR, users());
                return 1;
        }
        wiz_name = me->query("name");
        wiz_id = me->query("id");
        if(arg == "now") {
                if(query_wiz_level(wiz_status) < query_wiz_level("(admin)"))
                        return notify_fail("只有 (admin) 巫师才有权立即启动" + CHINESE_MUD_NAME + "\n");
                message("system",HIR+"大家请注意！"+HIY"【"+CHINESE_MUD_NAME+"】"NOR+"将在"+WHT"十秒钟"NOR+
                "后重新启动！\n请立即将档案存盘！！！\n" NOR,users() );
                call_out("countdown", 10, 1);
        } else {
                message("system",HIR+"大家请注意！"+HIY"【"+CHINESE_MUD_NAME+"】"NOR+"将在"+WHT"三分钟"NOR+
                "后重新启动！\n请抓紧时间作好准备，将档案及时存盘！！\n" NOR,users() );
                call_out("countdown", 60, 3);
        }
        return 1;
}

protected void countdown(int min)
{
        min--;
        if( min ) {
                message("system",HIR+"请注意！！！"+WHT+"还有" + chinese_number(min) + "分钟"+NOR+
                "的时间系统就要重新启动了！\n请抓紧时间存盘！！\n"+NOR,users() );
                call_out("countdown", 60, min);
        } else {
                message("system",HIW+"重新启动"+HIY+"【"+CHINESE_MUD_NAME+"】"+NOR+
                " ……\n请稍候一分钟再登陆！！谢谢！\n"NOR,users() );
                write_file(REBOOTFILE,sprintf("%s（%s）:%d",wiz_name,wiz_id,time()),1);
                do_shutdown();
        }
}


int help (object me)
{
        write(@HELP
指令格式: reboot [now]
 
重新起动游戏, 系统会开始倒数计时, 三分钟後重新起动。
加 now 选项时，系统将在十秒后从新启动（慎用！）。
HELP);
        return 1;
}

