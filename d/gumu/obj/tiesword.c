#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( CYN "玄铁剑" NOR, ({ "xuantiesword", "xuantie sword", "sword" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
                        
"一柄十分沉重的铁剑，此剑属天下三件神兵利器之一。剑主：杨过。\n"
);
               set("weapon_prop/intelligence",2);
 		 set("value", 38000);
	       
                set("material", "steel");
	        set("no_give", "这样东西不能离开你。\n");
	        set("no_drop", "这样东西不能离开你。\n");
	        set("no_get", "这样东西不能离开那儿。\n");
                set("wield_msg", "只听铛的一声，$N已把$n装备在手中。\n");
                set("unequip_msg", "$N将手中的$n已经入鞘。\n");
                set("is_xuantie-sword", 1);
        }

        init_sword(600);
        setup();}
void owner_is_killed(object killer)
{
	set("long","一柄十分沉重的铁剑，此剑属天下三件神兵利器之一。剑主："+HIY+killer->query("name")+NOR+"。\n");
	
}





