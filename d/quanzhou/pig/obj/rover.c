
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Ʈ�ħ��", ({ "rover" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����ħ�����·�������������һ�ɵ��㣬����ȥ�о���Ʈ翡�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
        }
        setup();
}

