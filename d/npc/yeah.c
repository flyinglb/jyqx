#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"无情"NOR, ({"Yeah"}));
	set("nickname",HIR"四大巡捕之"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他无疑是新金庸群侠传II中第二代高手的代表人物，现在他
也做了巫师，成为泥潭中最熟悉每一个角落的人物。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
