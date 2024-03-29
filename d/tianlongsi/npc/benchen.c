// benchen.c
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("本尘", ({ "ben chen","chen"}) );
	set("gender", "男性" );
	set("long", "他就是天南为帝的大理保定帝段正明。大理历代国主均逊位
天龙寺出家为僧，保定帝亦不例外。\n" );
	set("title", "天龙寺第十七代僧人");
	set("class", "bonze");
	set("age", 45);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 120);
	set_skill("dodge", 180);
	set_skill("parry", 120);
	set_skill("finger", 185);
	set_skill("sword", 120);
	set_skill("tiannan-step", 180);
	set_skill("kurong-changong", 120);
	set_skill("duanjia-sword", 120);
	set_skill("six-finger", 180);
	set_skill("buddhism", 100);
	set_skill("literate", 80);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");
	create_family("大理段家",17,"高僧");
	setup();
	carry_object("/d/xueshan/obj/b-jiasha")->wear();
}
#include "ben.h"
