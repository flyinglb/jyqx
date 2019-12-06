#include <ansi.h>
inherit NPC;
void create()
{
	set_name("天罡神龙", ({ "qingfeng"}));
	set("title", HIM"〖飘"HIW"雪"HIM"山庄〗"BLINK+HIR"★神龙护法★"NOR );
	set("long", "只见他面如冠玉，目若朗星，鼻直口阔，貌胜潘安\n");
	set("gender", "男性");
	set("age", 25);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 400);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("changquan", 200);
	set_skill("kuihua-xinfa", 200);
	set_skill("lingxu-bu", 200);
	set_skill("damo-jian", 200);
	set_skill("taiji-jian", 200);
	set_skill("huifeng-jian", 200);
	set_skill("taishan-sword", 200);
	set_skill("hengshan-jian", 200);
	set_skill("hengshan-sword", 200);
	set_skill("huashan-sword", 200);
	set_skill("songshan-sword", 200);

	map_skill("dodge", "lingxu-bu");
	map_skill("force", "kuihua-xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}