// zichoushan.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�ϳ���", ({ "zichou shan","shan","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("value",400);
                 set("armor_prop/armor", 60);
        }
        setup();
}

