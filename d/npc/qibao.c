#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"渡净"NOR, ({"Qibao"}));
        set("nickname",HIR"铁血山庄 "HIW"· "BLINK+HIC"二庄主 太过在乎你"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",28);
	set("long",@LONG
据说他练功速度最快，曾创造一代武林神话……
到成为“名人”的时候：总共杀了 4674 个人，其中有 0 个是其他玩家。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
