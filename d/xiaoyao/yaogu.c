// Room: /xiaoyao/yaogu.c
inherit ROOM;

void create()
{
        set("short", "药谷");
        set("long", @LONG
这是薛老爷子叫人挖药的后山，这里的每一株树，每一颗草在你的眼中看
来可能不算什么，在薛老爷子那里都可能是价值连城的宝贝。四处是刚挖过的
新土，显然来这里为薛老爷子挖药的人不少。
LONG );
        set("outdoors", "xiaoyao");
        set("exits", ([
                "north" : "/d/xiaoyao/muwu1",
        ]));
        set("caoyao" , 500);
        setup();
}

void init()
{
        add_action("do_dig", "wa");
}

int do_dig(string arg)
{
        object me, ob;
        string str;
        me = this_player();
        if( me->query("family/family_name") != "逍遥派" ) return 0;
        if( !me->query_temp("job_xiaoyao_tool") ) return 0;
        if( !objectp(present("yao chu", me)) )
                return notify_fail("你没有工具怎么挖？\n");
        if (!arg || (arg != "药" && arg != "yao"))
                return notify_fail("你拿着锄头不知道该从那里下手。\n");
        if(!me->query_temp("job_xiaoyao"))
                return notify_fail("你得先经过掌门同意了才能挖药\n");
        if( me->is_busy() )
                return notify_fail("你的上一个动作还没有完成。\n");
        if( me->is_fighting() )
                return notify_fail("你现在正忙着打架呢。\n");
        if( (int)me->query("jing") < 50)
                return notify_fail("你已经累得连锄头都拿不稳了，怎么挖？\n");
        message_vision("$N拿起药锄，在这不停的挖了起来......\n",me);
        me->add("jing",-(20+random(10)));
        me->start_busy(1);
        if(query("caoyao")<=0) {
                message_vision("$N挖了一会，发现这里已经没有草药可挖了！\n",me);
                return 1;
        }
        if(random(16) < 2) {
                message_vision(HIY"$N挖着挖着，突然发现了一株特别的草！\n"NOR,me);
                ob = new(__DIR__"obj/caoyao");
                ob->move(me);
                environment(me)->add("caoyao",-1);
                me->delete_temp("job_xiaoyao");
                ob->set_temp("finish_id",me->query("id"));
                tell_object(me,"你挖到了一棵草药。\n");
        }
        if(random(20) == 1) {
                if(me->query_temp("job_xiaoyao_finish")) str ="兴奋";
                else str = "用力";
                message_vision(HIG"只见$N"+str+"过度，噶蹦一声$N手中的药锄断了！\n"NOR, me);
                destruct(present("yao chu", me));
        }
        if(random(10) == 1) {
                if(me->query("combat_exp")<=5000)
                    ob = new(__DIR__"npc/bee");
                else if(me->query("combat_exp")<=10000)
                    ob = new(__DIR__"npc/monkey");
                else if(me->query("combat_exp")<=20000)
                    ob = new(__DIR__"npc/deer");
                else if(me->query("combat_exp")<=30000)
                    ob = new(__DIR__"npc/snake");
                else if(me->query("combat_exp")<=50000)
                    ob = new(__DIR__"npc/laohu");
                else {
                    ob = new(__DIR__"npc/laohu");
                    ob->set("combat_exp", 490000+random(10000));
                    ob->set_temp("apply/attack", 300);
                    ob->set_temp("apply/defense", 200);
                    ob->set_temp("apply/damage", 10);
                    ob->set_temp("apply/armor", 100);
                }
                ob->move(this_object());
                message_vision(HIR"$N一不小心惊动了一"+ob->query("unit")+
                "$n，$n发疯似的向$N发起攻击！\n"NOR,me,ob);
                ob->kill_ob(me);
                me->fight_ob(ob);
        }
        return 1;
}
