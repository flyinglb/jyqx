
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("��Ƥ����", ({ "diaopi dayi", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ��ѡ���Ϻ���Ƥ�������ƵĴ��¡�\n");
                set("material", "cloth");
		set("value", 100000);
                set("armor_prop/armor", 5);
        }
        setup();
}

