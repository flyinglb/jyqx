//LUCAS 2000-6-18
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"���ڵ���"NOR, ({ "jinwu-book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
//                set("no_drop",1);
                set("long",
                        "����һ��ѧϰ���ڵ������顣\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name":         "jinwu-blade",       // name of the skill
                        "exp_required": 10000,                  // minimum combat experience required
                                                                // to learn this skill.
                        "jing_cost" :   30,
                        "difficulty":   30,                     // the base int to learn this skill
                                                                // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    100,                     // the maximum level you can learn
                        "min_skill":    0                       // the maximum level you can learn
                                                                // from this object.
                ]) );
        }
}

