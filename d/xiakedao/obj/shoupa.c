//shoupa.c
#include <armor.h>
inherit ITEM;
void create()
{
        set_name( "����", ({ "shou pa"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��Ư����������\n");
                set("value", 50);
                set("material", "cloth");
                set("female_only", 1);
                set("armor_prop/armor", 3);
       }
}
