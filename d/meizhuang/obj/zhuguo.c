// zhuguo.c
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣����ΰ�! \n");
                set("no_drop","����㶼���ӣ�\n");
        }

        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR "���" NOR, ({"zhu guo", "guo"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ�������ͨ���ʺ죬һ����֪�ǲ��ɶ�õ���Ʒ��\n");
                set("value", 100000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
//        me->set("eff_jing", (int)me->query("max_jing"));
//        me->set("jing", (int)me->query("max_jing"));
//        me->set("eff_qi", (int)me->query("max_qi"));
//        me->set("qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("eff_qi"));
        me->set("neili", (int)me->query("max_neili"));
//        me->set("jingli", (int)me->query("max_jingli"));
//        me->set("food", (int)me->max_food_capacity());
//        me->set("water", (int)me->max_water_capacity());
          message_vision(HIR
 "$N����һ�������ֻ������ȫ����һ��ů���ӵ���ֱ��������\n"NOR,me);

        destruct(this_object());
        return 1;
}
