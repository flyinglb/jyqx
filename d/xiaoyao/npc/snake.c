// animal: snake.c

inherit NPC;

void create()
{
        set_name("毒蛇", ({ "snake", "she" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "一只有着三角形脑袋的蛇，尾巴沙沙做响。\n");
      set("attitude", "peaceful");
      
        set("str", 26);
        set("cor", 30);
        set("shen_type", -1);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 29000+random(1000));

        set_temp("apply/attack", 500);
        set_temp("apply/defense", 300);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 500);
        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
        random(ob->query_kar() + ob->query_per()) < 30) {
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, ob); 
        }
}

void die()
{
        object ob;
        message_vision("$N啪的一声断成两截！$N死了。\n", this_object());
        ob = new(__DIR__"obj/shedan");
        ob->move(environment(this_object()));
        destruct(this_object());
}
