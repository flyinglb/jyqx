#include <ansi.h>

inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW"明目丹"NOR, ({"mingmu dan", "dan","mingmu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一粒珍贵的明目丹。\n");
                set("value", 200);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        
        if (!id(arg)||(arg!="dan"&&arg!="mingmu dan"))
	        return 0;
        if (me->query("age") >= 15)
        return notify_fail("你长大了，明目丹对你不起作用了。\n");
        if (me->is_busy() )
                return notify_fail("别急，慢慢吃，小心别噎着了。\n");
        if(me->query_condition("mingmu_drug")>0) {
                me->receive_damage("jing",10);
                me->receive_damage("qi",20);
                me->receive_wound("jing",10);
                me->receive_wound("qi",20);
                message_vision(HIB "$N吃下一粒明目丹，顿然间只觉一股寒气直灌百汇... 原来是服药过猛适得其反！\n" NOR, this_player());
        } else {
                me->add("eff_jing",10);
                me->add("max_jing",10);
                me->apply_condition("mingmu_drug", 120);
                message_vision(HIW "$N吃下一粒明目丹，顿然间只觉一股清凉之气自双目透出...\n" NOR, this_player());
        }
	this_object()->move(VOID_OB);
        destruct(this_object());
	me->start_busy(2);
        return 1;
}

