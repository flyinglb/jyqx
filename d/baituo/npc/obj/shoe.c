//key.c
#include <armor.h>
inherit ITEM;
void create()
{
        set_name( "�廨Ь", ({ "shoe"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long","����һֻƯ�����廨Ь��\n");
                set("value", 50);
                set("material", "cloth");
                set("female_only", 1);
        	set("armor_prop/armor", 3);
              }
}
