#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIC "紫薇软剑" NOR, ({ "ziwei-sword" , "jian", "sword"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
                        
"一柄软剑，再看那剑时，见长约四尺，青光闪闪，的是利器。\n"
);
               set("weapon_prop/intelligence",2);
 		 set("value", 38000);
	       
                set("material", "steel");
                set("wield_msg", "只见一道白光的，$N已把$n装备在手中。\n");
                set("unequip_msg", "$N将手中的$n已经入鞘。\n");
        }

        init_sword(200);
        setup();}
void owner_is_killed(object killer)
{
	set("long","一柄轻巧锋利的软剑，此剑属天下三件神兵利器之一。剑主："+HIY+killer->query("name")+NOR+"。\n");
	
}





