// moyao.c ûҩ
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW"ûҩ"NOR, ({"moyao"}));
        set_weight(500);
        set("unit", "��");
        set("long", "����һ������ҩ��-ûҩ������������ҩ��\n");
        setup();
}

int do_eat(string arg)
{
        if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="moyao")
        {
                write("���������ڰ�ûҩ������ȥ��\n");
                destruct(this_object());
        }
        return 1;
}
