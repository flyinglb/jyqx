// xiongdan.c �ܵ�
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"�ܵ�"NOR, ({"xiongdan"}));
        set_weight(1000);
        set("unit", "��");
        set("long", "����һ���ʺ���ܵ�������������ҩ��\n");
        setup();
}

int do_eat(string arg)
{
        if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="xiongdan")
        {
                write("���������ڰ��ܵ�������ȥ��\n");
                destruct(this_object());
        }
        return 1;
}

