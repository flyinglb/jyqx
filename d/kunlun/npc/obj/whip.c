#include <weapon.h>
inherit WHIP;

void create()
{
	set_name( HIG "策犬鞭" NOR, ({ "cequanbian", "bian" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是一柄带有倒刺的长鞭，用牛皮和精铁编织而成。\n");
		set("value", 10000);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一条$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(50);
	setup();
}
