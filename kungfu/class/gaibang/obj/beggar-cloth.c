// beggar-cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("��ؤ����", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ�����õĲ��£���������˲�����\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 1);
        }
        setup();
}
