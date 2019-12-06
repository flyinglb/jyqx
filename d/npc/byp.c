#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"白云飘"NOR, ({"Byp"}));
	set("nickname",HIW"杀虫剂"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他当今新金庸群侠传II的主要程序设计人。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
