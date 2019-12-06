#include <ansi.h>

inherit ITEM;

int j, i;

void make_bs(object me, object ob, int j);  

void create()
{
        set_name("福威镖队", ({ "fuwei"}));
        set("unit", "只");
        set_weight(90000000);
        set("long", "
一只远道而来的镖队，上面堆满了货物。中间插
着一面镖旗，似乎写着“福威镖局”四个大字。。。\n");
        set("no_get", 1);
        set("no_drop", 1);
        set("no_put",1);

        j = query_temp("j");
        if (j=4)
                set("i", 4);
        else if (j=5)
                set("i", 5);
        else if (j>6)
                set("i", 6);
        else
                set("i", 3);

}

void init()
{
        remove_call_out("aaa");
        call_out("aaa", 60, this_object());  
        add_action("do_rob", "qiang");
}

int do_rob()
{
        object me, ob;
        string arg;
        int stage;
        me = this_player();
        ob = this_object();
        stage = 0;
        arg = query("arg");

        ob -> set("rob_id",query("id"));
        
        if(!living(me))
                return 0;
        
        if(!me->query_temp("rob_start")) 
                return notify_fail("你胆子不小，竟敢在福威镖局头上打注意？\n");
        
        if(objectp(present("biaoshi", environment(me))))
                return notify_fail("护镖镖师看来武功不弱，你还是先打发了面前这个再说吧！\n");  

        message_vision(HIY"$N对着$n大吼一声：呔！\n此山是我开，此树是我载，\n要打此路过，留下买路财！！！\n"NOR, me, ob);
        me->set_temp("xx_rob", 1);
        make_bs(me, ob, j); 
        return 1;     
}

void make_bs(object me, object ob, int j)
{
        object obj, obj1;

        
        j = me->query_temp("j");
        i = ob->query("i");


                obj1 = new(__DIR__"tangzishou");
                obj1 -> move(environment(me));
                message_vision(HIR"突然从车队后窜出一个$N，二话不说就扑向了$n！\n"NOR, obj1, me);
//                obj1 -> go_back(me);
                obj1 -> kill_ob(me);
                me -> kill_ob(obj1);

        if (j>0){
                if (random(i))
                        obj=new(__DIR__"tangzishou");
                else {
                        obj=new(__DIR__"biaoshi");
                        obj->copy_player(me);
//                        obj->do_copy(me);
                }
                obj -> move(environment(me));
                message_vision(HIR"突然从车队后窜出一个$N，二话不说就扑向了$n！\n"NOR, obj, me);
                obj -> kill_ob(me);
                me -> kill_ob(obj);
                ob -> query("last_opponent", ob ->query_temp("last_opponent") );
//                obj -> go_back(me);

                j = j-1;
                me -> set_temp("j",j);
        }
        else {
                message_vision(HIW"$N见已经无人保护，将镖车中所带的财物全都拿在怀里！\n随手把镖车破坏，以免日后被人查出。\n"NOR, me);    
                obj=new(__DIR__"red");
                obj->move(me);
                obj->set("owner", me->query("id"));
                me->add("shen", -100);
                me->delete_temp("rob_start");
                me->delete_temp("xx_rob");
                me->delete_temp("rob_job");
                me->delete_temp("j"); 
                me->delete("i");
                destruct(ob);
                remove_call_out("aaa");
                return;                 
        }
}

void aaa(object me)
{
        message_vision("$N转过几个小山丘就不见了。\n",me);
        me->delete_temp("rob_start");
        me->delete_temp("xx_rob");
        me->delete_temp("rob_job");
        me->delete_temp("j");
        destruct(me);
        return;
}


