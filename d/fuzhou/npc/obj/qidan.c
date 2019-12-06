#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY"大力丸"NOR, ({"dali wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一粒用途古怪的大力丸。\n");
                set("value", 2000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        
        if (!id(arg)||(arg!="wan"&&arg!="dali wan"))
        return notify_fail("你要吃什么？\n");
        if (me->query("age") >= 19)
        return notify_fail("你长大了，大力丸对你不起作用了。\n");
        if (me->is_busy() )
                return notify_fail("别急，慢慢吃，小心别噎着了。\n");

        if(me->query_condition("dali_drug")>0) {
                me->receive_damage("jing",10);
                me->receive_damage("qi",20);
                me->receive_wound("jing",10);
                me->receive_wound("qi",20);
                message_vision(HIB "$N吃下一粒大力丸，顿然间只觉全身热火难耐... 原来是服药过猛适得其反！\n" NOR, this_player());
        } else {
                me->add("eff_qi",15);
                me->add("max_qi",15);
                me->apply_condition("dali_drug", 120);
                message_vision(HIW "$N吃下一粒大力丸，顿然间只觉增加了一股特别的力量...\n" NOR, this_player());
        }
        this_object()->move(VOID_OB);
        destruct(this_object());
        me->start_busy(2);
        return 1;
}
