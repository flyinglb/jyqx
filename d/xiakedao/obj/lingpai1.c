// lingpai1.c ���Ʒ�����

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
        set_name("���Ʒ�����", ({ "ling pai", "pai" }));
        set("long", "����һ�����ɫ�����ƣ�������һ��Ц�������������������֡�\n"+
         "������һ�������ı��飬���з����������ӡ�����ǽ����ϴ�˵�����Ʒ����\n");
        set("weight", 300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50000);
                set("material", "��");
                set("armor_prop/armor", 2);
        }
        setup();
}
