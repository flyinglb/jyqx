inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;
void create()
{
        set_name(MAG "����ͩ" NOR, ({"huo qingtong", "huo" }));
        set("title", HIW "����"YEL"����" NOR);
        set("shen_type", 5);
        set("gender", "Ů��");
        set("per",48);
        set("long",
                "�����ǻؽ��������˳ơ��������������ͩ��\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "�¼���" : "sigh�����ǲ�Ҫ���ˡ�\n",
        ]));
        set("neili", 200);
        set("max_neili", 100);
        set("jiali", 10);
        set("shen", 0);
        set("combat_exp", 12500);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("sword",50);
	    set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
         carry_object(__DIR__"obj/duanjian")->wield();
         carry_object(__DIR__"obj/ycloth")->wear();
}
/*
void init()
{
        object ob;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
// void greeting(object ob)
// {
//        if (!ob || environment(ob) != environment())
//               return;
//        switch(random(2)) {
//        case 0 :
//                say("������Ц���е�˵������λ" + RANK_D->query_respect(ob) +
//                        "�������������ơ�\n");
//                break;
//        case 1 :
//                say("������˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
//                        "�����˰��������иճ�Ҥ�ĺþơ�\n");
//                break;
//        }
// }
*/
