// xuantie.c ������

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
        set_name(HIC "������" NOR, ({ "xuan tie", "xuan" }));
        set("long", "\n����һ�����ɫ�����ƣ�Ө����̣�����һ�����\n"+
         "��������̷����д�������������֡�����ǽ����ϴ�˵�������\n");
        set("weight", 300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50000);
                set("material", "��");
                set("armor_prop/armor", 2);
                set("female_only", 1);
        }
        setup();
}
