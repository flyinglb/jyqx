// cloth: wcloth.c
// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("ά����峤��", ({ "weiwuer robe", "robe"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ɫ�ʰ�쵵�ά����峤��\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 50);
        }
        setup();
}

