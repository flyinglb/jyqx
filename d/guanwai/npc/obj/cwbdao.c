//cwbdao.c
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(HIC"闯王宝刀"NOR, ({ "chuangwang baodao", "blade","baodao" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 0);
        	set("material", "iron");
        	set("long", "这是闯王所使用过的刀，上面刻有几行小字。\n" );
        	set("wield_msg",HIW"一道白光，"+HIC+"$n"+HIW+"已在$N手中，只觉青光四射，寒气透骨，不禁机伶伶的打个冷战。\n"NOR);
        	set("unwield_msg", HIG"$N将"+HIC+"$n"+HIG+"插回腰间，华光顿敛，天地间只闻龙鸣。\n"NOR);
	}
	init_blade(350);
	setup();
}
