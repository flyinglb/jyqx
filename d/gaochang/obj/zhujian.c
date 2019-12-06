// book4.c
inherit ITEM;

void create()
{
    set_name("竹简", ({ "zhu jian", "jian"}));
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "块");
        set("long",
           "这些竹简已经放在这里太久了，可能一拿起来就会散开。\n你发现上面写着一些奇怪的...。\n");
        set("value", 500);
        set("material", "stone");
       set("no_get",1);
                setup ();
    }
}
void init()
{
        add_action("do_study", "study");
}


int do_study(string arg)
{
        object me;
        int    jing_cost;
        me = this_player();

        if (!me->query_temp("竹简"))
                     return notify_fail("你要读什么1？");
                if ( !arg || ( arg != "zhu jian" ) )
               return notify_fail("你要读什么2？");

        if ( (int)me->query_skill("literate", 1) < 1){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        if ( (int)me->query_int() < 55){
                write("你的悟性不够，先学点文化(literate)吧。\n");
                return 1;
        }
        jing_cost = me->query("max_jing")/5;
        if((int)me->query("jing") < jing_cost){
                write("你看了看地上的竹简，似乎悟出了一些东西。\n");
                return 1;
        }
        me->receive_damage("jing", jing_cost );
        me->delete_temp("stone_learned");

        message_vision("$N正专心研读地上的竹简。\n", me);
        
        write("你对着竹简琢磨了一回儿，似有所悟。\n");

        if ( (int)me->query_skill("axe", 1) < 1000 && random(10)>3 ){
                        me->improve_skill("axe", me->query_int());
                        me->set_temp("stone_learned",1);
                }
        return 1;
}
