#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"塞备斯"NOR, ({"Sybase"}));
	set("nickname",MAG"＊神州结义＊"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他是新金庸群侠传II中成长最快的高手，迅速成为第三代高手
中的佼佼者。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
