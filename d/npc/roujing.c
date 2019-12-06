#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"水柔晶"NOR, ({"Roujing"}));
	set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+HIM+"新月堂堂主 "+HIC+"新月格格"NOR);
	set("gender", "女性");
	set("age", 25);
	set("per",31);
	set("long",@LONG
水柔晶是这里一个调皮的小女孩，脾气时好时坏，好的时候帮
助新人，坏的时候作弄人。新玩家小心被作弄啊！她可是这里
第一个上名人堂的女玩家哦。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
