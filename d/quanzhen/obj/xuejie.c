// xuejie.c Ѫ��
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(RED"Ѫ��"NOR, ({"xuejie"}));
        set_weight(800);
        set("unit", "��");
        set("long", "����һ���ʺ��Ѫ�ߣ�����������ҩ��\n");
        setup();
}

int do_eat(string arg)
{
        if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="xuejie")
        {
                write("���������ڰ�Ѫ�߳�����ȥ��\n");
                destruct(this_object());
        }
        return 1;
}
