// go.c
// Modified by Eatdami@MX (10/16/2000)

inherit F_CLEAN_UP;

mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
        "out":          "外",
        "enter":        "里",
]);

void create() { seteuid(getuid()); }

//add Byp@MX 
void consume_jingli(object me)
{
        //根据身法负重来消耗
        int cost,i_jl;
        float f_jl;
        
        
        if( !userp(me) ) return;
        cost = (me->query_encumbrance()*100/me->query_max_encumbrance() ) - me->query_dex();
        if( cost < 10 ) cost = 10;//每次移动最低消耗 1/10 精力
        f_jl = me->query("Amend_JingLi") + to_float(cost) / 100;
        i_jl = f_jl;//很奇怪，driver 在 to_int 转换的时候好象有些问题
        if( f_jl > 1.0000 ) {
                me->set("Amend_JingLi",f_jl - i_jl );
                me->add("jingli",- i_jl );
        } else {
                f_jl = to_float(cost)/100;
                me->add("Amend_JingLi",f_jl);
        }
}

int main(object me, string arg)
{
	string dest, mout, min, dir, msg;
        object env, obj;
        int mq,eq;
        mapping exit;
        object *f_obs,*ob;
        int count = 0, my_dex, i;

        mq=(int)me->query("max_qi");
        eq=(int)me->query("eff_qi");
        if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if( userp(me) && me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");

        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");

        if( userp(me) && me->query("jingli") < 1 )//add Byp@MX 
                return notify_fail("你现在累及了，无法在移动半步。\n");

        if (me->is_fighting()) {
                f_obs = me->query_enemy();
                if (objectp(f_obs[0]))
                if (5 + random((int)me->query("dex")) <=
                       random((int)f_obs[0]->query("dex"))) {
                        me->start_busy(1);
                        message_vision("$N见势不好，转身要走，被$n一把拦在面前。想走？没那么容易！\n", me, f_obs[0]);
                        return notify_fail("你逃跑失败。\n");
                }
        }

        env = environment(me);
        if(!env) return notify_fail("你哪里也去不了。\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("这个方向没有出路。\n");
//                        return notify_fail("咚！的一声你感到头晕目眩似乎撞到什么硬东西！\n你发现这个方向没有出路。\n");
                else
                        return 0;
        }

        dest = exit[arg];

        if( !(obj = load_object(dest)) )
                return notify_fail("无法移动。\n");

        ob = all_inventory(obj);
        for(i=0; i<sizeof(ob); i++)
                if( living(ob[i]) && ob[i] != me )
                        count++;
        my_dex = (int)me->query_dex();

/*
        if(!obj->is_chatting_room()
        && (((my_dex < 15) && (count > 6))
        || ((my_dex < 20) && (count > 8))
        || ((my_dex < 30) && (count > 10))
        || ((my_dex < 35) && (count > 12))
        || ((my_dex < 40) && (count > 16))
        || ((my_dex < 45) && (count > 20))
        || (count > 30)))
*/
        if( !obj->is_chatting_room() && count > my_dex / 3 * 10)
                return notify_fail("前面人太多了，你怎么挤也挤不过去。\n");
        if( !env->valid_leave(me, arg) ) return 0;

        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;

        if( me->is_fighting() ) {
                mout = "往" + dir + "落荒而逃了。\n";
                min = "跌跌撞撞地跑了过来，模样有些狼狈。\n";
             }
	else
        if(100*eq/mq<=30 ){
        mout = RED"不住地呻吟，拖着遍体鳞伤的残体向" + dir + "爬去。地上赫然留下一道道斑斑的血迹。\n"NOR;
        min = RED"不住地呻吟，拖着遍体鳞伤的残体爬了过来。\n"NOR;
        } else
        if(100*eq/mq<=50 ){
        mout = RED"撑起满是鲜血的躯体，一瘸一拐地朝" + dir + "挪去。\n"NOR;
        min =RED"撑着满是鲜血的躯体，一瘸一拐地挪了过来。\n"NOR;
        } else
        if(100*eq/mq<=70){
        mout = HIC"一边擦着嘴角的鲜血，一边朝" +dir+"走去。\n"NOR;
        min = HIC"一边擦着嘴角的鲜血，一边走了过来，龇牙咧嘴的。\n"NOR;
        } else
        if(100*eq/mq<=90 ){
        mout = WHT"灰头土脸、狼狈不堪地向"+dir+"离去。\n"NOR;
        min = WHT"灰头土脸、狼狈不堪地走了过来。\n"NOR;
        } else
        if(100*eq/mq<=95){
        mout = CYN"故作镇定地转身朝"+dir+"走去，屁股上赫然一个脚印。\n"NOR;
        min = CYN"故作镇定地走了过来，全然不知刚才的那一脚的印迹还留在屁股上。\n"NOR;
        } else {
                mout = "往" + dir + "走去。\n";
                min = "走了过来。\n";
        }

       if( wizardp(me) && me->query("env/invisibility") 
	&&(wiz_level(me) >= wiz_level(env)))
	{
		msg = "";
        } else
        msg = me->name() + mout;
        //message( "vision", me->name() + mout, environment(me), ({me}) );
        message( "vision", msg, environment(me), ({me}) );
        if( me->move(obj) ) {
                me->remove_all_enemy();
       if( wizardp(me) && me->query("env/invisibility") 
	&&(wiz_level(me) >= wiz_level(env)))
	{
		msg = "";
        } else
		msg = me->name() + min;
                //message( "vision", me->name() + min, environment(me), ({me}) );
        message( "vision", msg, environment(me), ({me}) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);
                if( !obj->is_chatting_room() ) consume_jingli(me);//add Byp@MX 
                return 1;
        }

        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");
        if( !mapp(exits) || !sizeof(exits) ) return;
        directions = keys(exits);
        tell_object(me, "看来该找机会逃跑了...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
指令格式 : go <方向>

让你往指定的方向移动。

HELP
    );
    return 1;
}
