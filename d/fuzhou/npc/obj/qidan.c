#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY"������"NOR, ({"dali wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����;�ŹֵĴ����衣\n");
                set("value", 2000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        
        if (!id(arg)||(arg!="wan"&&arg!="dali wan"))
        return notify_fail("��Ҫ��ʲô��\n");
        if (me->query("age") >= 19)
        return notify_fail("�㳤���ˣ���������㲻�������ˡ�\n");
        if (me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

        if(me->query_condition("dali_drug")>0) {
                me->receive_damage("jing",10);
                me->receive_damage("qi",20);
                me->receive_wound("jing",10);
                me->receive_wound("qi",20);
                message_vision(HIB "$N����һ�������裬��Ȼ��ֻ��ȫ���Ȼ�����... ԭ���Ƿ�ҩ�����ʵ��䷴��\n" NOR, this_player());
        } else {
                me->add("eff_qi",15);
                me->add("max_qi",15);
                me->apply_condition("dali_drug", 120);
                message_vision(HIW "$N����һ�������裬��Ȼ��ֻ��������һ���ر������...\n" NOR, this_player());
        }
        this_object()->move(VOID_OB);
        destruct(this_object());
        me->start_busy(2);
        return 1;
}
