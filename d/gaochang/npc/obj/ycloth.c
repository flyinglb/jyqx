// cloth: wcloth.c
// Jay 3/17/96
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("��Ƥ��", ({ "yangpi ao", "ao"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ɫ����Ƥ���������˲��ܴ����ﶬ, �η����궼��������\n");
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("value", 500);
        }
        setup();
}
