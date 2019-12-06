#include <ansi.h>
inherit NPC;

void create()
{
	set_name("朱长龄", ({ "zhu changling", "zhu" }));
	set("title", CYN "惊天一笔" NOR);
	set("long", "他是朱武连环庄之北庄的庄主，一付读书人打扮。\n");
	set("gender", "男性");
	set("age", 42);
	set("class", "swordman");
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 20);
	set("int", 25);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 350000);

        set_skill("force", 85);
        set_skill("dodge", 80);
        set_skill("parry", 85);
        set_skill("cuff", 80);
        set_skill("sword", 85);
	set_skill("kurong-changong", 85);
        set_skill("tiannan-step", 80);
        set_skill("jinyu-quan", 80);
        set_skill("duanjia-sword", 85);
	set_skill("literate", 120);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/clone/cloth/male2-cloth")->wear();
	carry_object(__DIR__"obj/swordpen")->wield();
	add_money("silver", 10);

}

