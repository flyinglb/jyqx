#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"凤舞九天"NOR, ({"Pipipipi"}));
        set("nickname",HIY"【"HIR"天魔宫"HIY"】"BLK"使者 "HIR"恶"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
              问人间  情是何物  直教生死相许
              天南地北双飞客  老翅几回寒暑
              欢乐趣  离别苦  此中更有痴儿女
              君应有语  渺万里层云  千山幕景  只影为谁去
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
