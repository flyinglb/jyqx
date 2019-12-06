
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIB"惊天笔"NOR, ({ "jingtian bi", "sword","jian" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是朱长龄为示文雅，以笔代剑的武器。\n");
                set("value", 150000);
                set("material", "steel");
                set("wield_msg", "$N缓缓抽出一支$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n收入了袖中。\n"NOR);
        }
        init_sword(50);
        setup();
}

