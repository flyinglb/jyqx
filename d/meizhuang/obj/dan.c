// dan.c
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣����ΰ�! \n");
                set("no_drop","��ô������ɵ�����������! \n");
        }
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG "�ɵ�" NOR, ({"dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long",
"����һö�ɵ�������ȥ����һֻСС�Ľ��«��");
                set("value", 100000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        me->set("water", (int)me->max_water_capacity());
        me->set("food", (int)me->max_food_capacity());
        message_vision(HIG
 "$N����һ���ɵ���ֻ���þ���������Ѫ��ӯ����ˬ��̫ˬ��! \n"NOR, me);

        destruct(this_object());
        return 1;
}

