#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(YEL "飞驼金甲" NOR, ({ "gold armor","armor","jia", }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value",500000);
                set("long", "这是一副用黄金打造而成的护甲，甲上雕刻着一群背生翅膀的骆驼
传说中只有高昌国王才可以使用飞驼标记。\n");
                set("armor_type", "cloth");
                set("armor_prop/dodge", 60);
                set("armor_prop/armor", 500);
        }
        setup();
}
