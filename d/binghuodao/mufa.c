// cloth.c
//
// This is the basic equip for players just login.

//#include <armor.h>

inherit ROOM;
// CLOTH;

void create()
{
        set("short",
"ľ��");
//  set("short", "С·");
        set("long", @LONG
һ��ľ��.
LONG );
/*        set_weight(3000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "skin");
               set("value",30);
               set("armor_prop/armor", 3);
        } */
        setup();
}


