//shepi

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name( HIW "ѩ��Ƥ" NOR, ({ "lang pi", "pi" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("value",15000);
                set("material", "leather");
                set("armor_prop/armor", 10);
        }
        setup();
}


