// yezhu.c

inherit NPC;

void create()
{
        set_name("Ұ��", ({ "pig", "yezhu" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", 
"����һֻ���͵�Ұ�����ü�Ϊ��׳�����ﻹ���Ϸ������µĺ�����\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 1000);
        set("shen_type", -1);

//      set("chat_chance", 6);
//      set("chat_msg", ({
//              (: this_object(), "random_move" :),
//      }) );

        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "Ұ���ڴ�ڵش����������꣡���꣡���꣡���꣡\n",
                "Ұ��ͻȻ�����������۾���ݺݵض����㣬��������Ҫ�˹�����\n"
        }) );

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

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
        message_vision("$N��ѽ�زҺ�һ�������ˣ�\n", this_object());
        ob = new("/d/xiakedao/obj/pigdie");
        ob->move(environment(this_object()));
        destruct(this_object());

}

