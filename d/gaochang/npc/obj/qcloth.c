// cloth: wcloth.c
// Jay 3/17/96
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�����˰�ȹ", ({ "ao qun", "qun"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��֯���컨�̲ݵİ�ȹ, ������Ů�����������š�\n");
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("value", 1000);
        }
        setup();
}
