// shane-bu.c ���Ʒ���

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
        set_name("���Ʒ���", ({ "shane bu", "bu" }));
        set("long", "����һ�����Ʒ��񲾣���ͷ�����Ž����ƶ�\n");
        set("weight", 300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "paper");
        }
        setup();
}
