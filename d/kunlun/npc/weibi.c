#include <ansi.h>
inherit NPC;

void create()
{
	set_name("卫璧", ({ "wei bi", "wei" }));
	set("long", "他是武烈的大徒弟。\n");
	set("gender", "男性");
	set("age", 21);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("per", 28);
	set("str", 24);
	set("int", 20);
	set("con", 20);
	set("dex", 18);
	
	set("max_qi", 500);
	set("max_jing", 400);
	set("neili", 500);
	set("max_neili", 500);
	set("combat_exp", 80000);

        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("sword", 50);
	set_skill("kurong-changong", 50);
        set_skill("tiannan-step", 50);
        set_skill("jinyu-quan", 50);
        set_skill("duanjia-sword", 50);
	set_skill("literate", 50);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/clone/cloth/male3-cloth")->wear();
	carry_object(__DIR__"obj/sword")->wield();
	add_money("silver", 10);

}
