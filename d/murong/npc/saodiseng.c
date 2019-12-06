// seng.c
inherit NPC;

void create()
{
        set_name("扫地老僧", ({"saodi seng","seng"}));
        set("long", "一个年迈的僧人，常年在次打扫藏经阁。
但从身手看起来武功深不可策\n" );
	set("gender", "男性");
	set("attitude", "peace");
	set("class", "bonze");

        set("age", 137);
	set("shen_type", 1);
        set("str", 50);
	set("con", 20);
	set("dex", 25);
        set("max_qi", 5000);
        set("max_jing", 2000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 50);
        set("combat_exp", 6500000);
        set("score", 5000);
        set("chat_chance_combat",40);
        set("chat_msg_combat", ({
        (: perform_action, "finger.jingmo" :)
        }));
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 250);
        set_skill("finger", 300);
        set_skill("yijinjing", 300);
        set_skill("shaolin-shenfa", 300);
        set_skill("dodge", 200);
        set_skill("sword", 250);
        set_skill("damo-jian", 300);
        set_skill("hunyuan-yiqi", 300);
        set_skill("yizhi-chan", 300);
	set_skill("dodge", 250);
	set_skill("parry", 250);
        map_skill("finger", "yizhi-chan");
        map_skill("force", "yijinjing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("sword", "damo-jian");
	setup();

        prepare_skill("finger","yizhi-chan");

	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
        carry_object("/d/shaolin/obj/zhujian")->wield();
	add_money("silver", 50);
}


