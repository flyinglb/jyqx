//yitianjian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name(HIW"倚天剑"NOR, ({ "yitian jian", "yitian","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 50000);
        	set("material", "iron");
        	set("long", "这是天下第一利器，有“倚天不出，谁与争锋”之说。\n");
        	set("wield_msg","直如矫龙吞水，长虹冠日一般，$n已在$N手中，天地为之变色。\n");
        	set("unwield_msg", "$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。\n");
                set("dynamic_quest", "/kungfu/class/mingjiao/zhangwuji");
	}
    	init_sword(500);
	setup();
}
