// quit.c
// a little modify by atu..
#include <mudlib.h>
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int slow_quit(object);
string time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        
        return time;
}

void create()
{
        seteuid(getuid());
        set("name", "离线指令");
        set("id", "quit");
        set("channel_id", "离线精灵");
}

int main(object me, string arg)
{
        object link_ob, env;
        env = environment(me);

        if( LOGIN_D->get_madlock())
                return notify_fail("时空已经封闭，没有人能够退出这个时空了。\n");
        if ( me->is_busy() && !wizardp(me) && !me->query_temp("suicide") && !me->query_temp("netdead") )
                 return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");
        if ( objectp(env) && env->query("no_quit") && !me->query_temp("netdead") )
                return notify_fail("对不起，这里不能退出。\n");
        if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

        if( me->over_encumbranced() && !me->query_temp("netdead") )
                return notify_fail("身上带的东西太多了，离不开游戏了。\n");

        link_ob = me->query_temp("link_ob");

        // We might be called on a link_dead player, so check this.
        if( link_ob ) {

                // Are we possessing in others body ?
                if( link_ob->is_character() ) {
                        write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
                        exec(link_ob, me);
                        link_ob->setup();
                        return 1;
                }

                link_ob->set("last_on", time());
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
                if( !wizardp(me) ) LOGIN_D->add_login_delay_ip(query_ip_number(me));
                destruct(link_ob);
        }
        if ( me->query_temp("will_quit") )
                return notify_fail("你已经准备退出了。\n");

        me->set_temp("will_quit",1);
        me->dismiss_team();

        if ( !wizardp(me) )
        {
                call_out("slow_quit", random(5)+3, me);
                write(HIR "你决定退出游戏，系统保存数据中，请稍候 ……\n" NOR);
        }
        else
                slow_quit(me);
        return 1;
}

protected int slow_quit(object me)
{
        int i,j;
        object *inv;

        if( !objectp(me) ) return 1;
        if( !wizardp(me) ) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( !inv[i]->query_autoload() )
                                DROP_CMD->do_drop(me, inv[i]);
        }
    
        write(HIY"谢谢您光临【"+CHINESE_MUD_NAME+"】！欢迎下次再来！\n"NOR);
        message("system", me->name() + "离开游戏。\n", environment(me), me);
//swapped it out..atu
/*
        CHANNEL_D->do_channel(this_object(), "sys",
                me->name() + "(" + me->query("id") + ")离开游戏了。共清除 " + reclaim_objects() + " 个变数。");
*/
	me->save();
	i=me->query("combat_exp")-me->query_temp("temp_exp");
	j=(int)(time()-me->query_temp("temp_time"));
	if (j < 1 ) j=1;
	CHANNEL_D->do_channel(this_object(), "sys",me->name(1) + "(" + me->query("id") + ")本次连线经验增长"+i+"。
	连线时间："+ time_period(j,me) +"。
        增长速度："+chinese_number(i*3600/j)+"点经验每小时。");//add by atu
	BAN_D->close_netclub(me); //关闭该网吧地址 by Eatdami@MX
	destruct(me);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quit | exit

当你(你)想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}
