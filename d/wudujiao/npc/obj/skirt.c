// skirt.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIR"���˿ȹ"NOR, ({ "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������˿֯�ɵ�ȹ�ӣ�����ȥ����⻬��\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 150);
//              set("value", 2000);
       }
        setup();
}

