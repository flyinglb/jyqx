#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"泪珠儿"NOR, ({"Shoe"}));
        set("nickname",HIY"【"HIW"慕容世家"HIY"】"HIM" 大小姐  "HIW"沉鱼落燕"NOR);
        set("gender", "女性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
据说她是超级大笨蛋的接班。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
