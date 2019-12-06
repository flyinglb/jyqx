// animal: snake.c

inherit NPC;

void create()
{
        set_name("����", ({ "snake", "she" }) );
        set("race", "Ұ��");
        set("age", 10);
        set("long", "һֻ�����������Դ����ߣ�β��ɳɳ���졣\n");
      set("attitude", "peaceful");
      
        set("str", 26);
        set("cor", 30);
        set("shen_type", -1);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
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
        message_vision("$Nž��һ���ϳ����أ�$N���ˡ�\n", this_object());
        ob = new(__DIR__"obj/shedan");
        ob->move(environment(this_object()));
        destruct(this_object());
}
