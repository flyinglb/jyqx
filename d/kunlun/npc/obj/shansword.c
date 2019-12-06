// black-sword.c 
// By Winzip 200.1.21 

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIY"三圣剑"NOR, ({ "shan sword", "sword","jian" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIB"这是当年昆仑三圣何足道所配带的宝剑。\n"NOR);
                set("value", 20000);
                set("material", "steel");
                set("wield_msg", HIR"$N「唰」地一声抽出一把$n"NOR HIR"握在手中,天空中登时一暗，仿佛乌云遮日一般！\n"NOR);
                set("unwield_msg", HIR"$N将手中的$n"NOR HIR"插入腰间的剑鞘，天空也随之一亮！\n"NOR);
        }
        init_sword(80);
        setup();
}

