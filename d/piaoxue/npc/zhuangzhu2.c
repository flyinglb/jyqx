inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("纪嫣然", ({ "yanran"}));
	set("nickname", "HIM"〖飘"HIW"雪"HIM"山庄〗"BLINK+HIR"★副庄主★");
	set("long", 
		"她就是飘雪山庄现任的庄主，前任庄主夫人，纪嫣然\n"
		"她身穿一件银红散花衣，显得魅力四射，风情万种\n"
		"她的面色白里透红，明眸皓齿，你看着看着不由得呆了。\n"
	set("gender", "女性");
	set("age", 30);
	set("attitude", "friendly");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("liangyi-jian", 200);
	set_skill("wudang-jian", 200);
	set_skill("taoism", 150);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");

	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
