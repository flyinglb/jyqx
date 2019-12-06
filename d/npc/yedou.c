#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"小叶"NOR, ({"Yedou"}));
        set("nickname",MAG"十步杀一人，千里不留行"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他是新金庸群虾传的第二代元老，为人和蔼可亲。虽然经验涨
得不是很快，但是其他方面却是可以。虽然也曾经干过一些
小偷小摸的事，却是无伤其整体的评价。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
