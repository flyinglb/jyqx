// /u/beyond/mr/cloth2.c
// this is made by beyond
// update 1997.6.20
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIY"��ɫ����" NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}


