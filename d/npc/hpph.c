#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"猫眯"NOR, ({"Hpph"}));
	set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+HIB+"长老 "+HIM+"丁丁猫"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他是新金庸群侠传的第三代玩家，进步很快，已经挤进一流高
手的行列。他为人朴实，乐于助人，与世无争，是一个好人。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
