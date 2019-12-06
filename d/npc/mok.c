#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"墨客"NOR, ({"Mok"}));
        set("nickname",HIR"【"HIW"七星楼"HIR"】"BLK" 影子刺客  "HIB"日月乾坤"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
这家伙很懒，什么都没留下。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
