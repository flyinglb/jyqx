#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("����ү", ({"xiang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������������ҩ������֮����Ҫ����������������ү�Ƶġ�\n");
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        if ( me->query("neili") >= me->query("max_neili")*2 )
        return notify_fail("������û��Ҫ������ү��\n");

        me->add("neili", 1);
        message_vision(HIY "$N����һ������ү��ֻ������������Ҫ���裡\n" NOR, me);

        destruct(this_object());
        return 1;
}

