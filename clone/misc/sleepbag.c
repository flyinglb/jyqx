// sleepbag.c
// Modified by Eatdami@MX (10/07/2000)

inherit ITEM;

protected void wakeup(object me,object where);
protected void del_sleeped(object me);
int do_sleep(string arg);

int is_container() { return 1; }
void create()
{
        set_name(YEL"睡袋"NOR,({"sleepbag"}));
        set_weight(5000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long", "一个睡袋，不知道是干什么用的。\n");
            set("unit","个");
            set("value", 1000);
        }
}

void init()
{
    if (environment()==this_player())
                add_action("do_sleep","sleep");
}
int do_sleep(string arg)
{
        int i;
        object me = this_player();
        object where = environment(me);

        if(arg) return 0;
        if( where->query("sleep_room") || where->query("freeze"))
                 return 0;
        if( where->query("no_sleep_room") )
                return 0;
        if( me->query("family/family_name") == "丐帮")
                return 0;
        if( me->is_busy() ) {
                write("你上一个动作未完成！\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("战斗中睡觉？挨宰呀？\n");
                return 1;
        }
        if (me->query_temp("sleeped")) {
                write("你刚睡过一觉, 还是去活动活动吧! \n");
                return 1;
        }
        message_vision("$N展开一个睡袋，钻了进去，不一会就进入了梦乡！\n",me);
        i = random(100/me->query_con()+2);
        where->add_temp("sleeping_person", 1);
        me->set("no_get", 1);
        me->set("no_get_from", 1);
        me->set_temp("block_msg/all",1);
        me->set_temp("sleeped",1);
        me->set_temp("in_sleeping",1);
        me->disable_player("<睡梦中>");
        me->set("last_sleep",time());
        if ( i < 1 )
                i = 0;
        call_out("wakeup", 5, me, where);
        return 1;
}


protected void wakeup(object me,object where)
{
        object env,env2;

        if( !objectp(me) )
                return;

        while( (env = environment(me)) && env->is_character() && (env2 = environment(env)))
                me->move(env2,1);

        me->set_temp("in_sleeping",0);
        me->set_temp("block_msg/all",0);
        me->enable_player();
        me->move(environment(me),1);
        env = environment(me);
        me->move(VOID_OB,1);
        me->move(env,1);

        if ( userp(me) && (!me->query("food") || !me->query("water")) ){
                message("vision",me->name()+"一觉醒来，肚子“咕”的一声，吓了大家一大跳。\n",environment(me),({me}));
                write("“咕”的一声，把你从梦中惊醒，发现原来是自己的肚子在打鼓！\n");
        }else{
                message("vision",me->name()+"一觉醒来，精力充沛地活动了一下筋骨。\n",environment(me),({me}));
                write("你一觉醒来，只觉精力充沛。该活动一下了。\n");
                me->set("qi",    me->query("eff_qi"));
                me->set("jing",  me->query("eff_jing"));
//                me->add("neili", me->query("max_neili")/3 - me->query("neili")/3 );
                me->add("jingli", me->query("max_jingli")/3 - me->query("jingli")/3 );
        }  
        call_out("del_sleeped", 5, me);
        if( where ) where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");
}

protected void del_sleeped(object me)
{
        if( !objectp(me) ) return;
        me->delete_temp("sleeped");
        me->set_temp("in_sleeping",0);
}
