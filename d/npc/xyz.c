#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"静静"NOR, ({"Xyz"}));
	set("nickname",HIC"峨嵋剑仙"NOR);
	set("gender", "女性");
	set("age", 35);
	set("per",30);
	set("long",@LONG
她是新金庸群侠传中第一代高手排名第一的，现在她已经退隐江
湖，继续做她在厦门侠客行100的顶级大天神。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
