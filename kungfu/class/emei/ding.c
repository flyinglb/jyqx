// ding.c 丁敏君

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("丁敏君", ({ "ding minjun","ding","minjun"}));
        set("long",
                "她是峨嵋派的第四代俗家弟子。是天下最恶心，无赖的人。\n");
        set("gender", "女性");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", -2);
        set("class", "fighter");

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("per", 10);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 150000);
        set("score", 1000);
        set_skill("force", 60);
        set_skill("throwing", 30);
        set_skill("dodge", 80);
        set_skill("finger", 70);
        set_skill("parry", 70);
        set_skill("strike", 70);
        set_skill("sword", 80);
        set_skill("jinding-zhang", 70);
        set_skill("tiangang-zhi", 70);
        set_skill("huifeng-jian", 80);
        set_skill("zhutian-bu", 80);
        set_skill("linji-zhuang", 70);

        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_hit","hit");
        add_action("do_kill","kill");
}

void greeting(object ob)
{
          if( !ob || environment(ob) != environment() ) return;
          command("chat " + ob->query("name")+"我好喜欢你啊！\n");
}
int do_hit(string arg)
{
          command("chat "+this_player()->query("name")+"要非礼我了！\n");
          return 1;
}
int do_kill(string arg)
{
          command("chat "+this_player()->query("name")+"这个混蛋要强奸我了！快来人哪！\n");
          return 1;
}
int accept_fight(object me)
{
          command("chat "+this_player()->query("name")+"要强奸我了，救命啊！\n");
          return 0;
}
