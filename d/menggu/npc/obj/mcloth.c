#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("��Ƥ��", ({ "yangpi ao", "ao"}) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ����Ƥ����\n");
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("value", 200);
        }
        setup();
}

