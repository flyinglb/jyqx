//wuxingfu.c ���е��ӷ�
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("���з�", ({ "wuxingfu" }));
        set("long", "�������е�����������\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 200);
                set("armor_prop/armor", 50);
        }
        setup();
}
