// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("������", ({ "da chang" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ͺӥ����֯�͵Ĵ��. \n");
                set("material", "cloth");
                set("armor_prop/armor", 15);
        }
        setup();
}

