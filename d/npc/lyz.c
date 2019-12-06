#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"静霜"NOR, ({"Lyz"}));
	set("nickname",HIG"女侠"NOR);
	set("gender", "女性");
	set("age", 35);
	set("per",29);
	set("long",@LONG
她是现在仍然活跃在泥潭中第一代三位顶尖高手中唯一的一
位，自静静退隐，黄百家成为巫师以后，她无疑就是江湖中言语
举足轻重的领袖人物了。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
