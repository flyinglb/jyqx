//LUCAS 2000-6-18
// feixue-book.c  
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"��ѩ����"NOR, ({ "feixue-book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
//                set("no_drop",1);
                set("long",
                        "����һ��ѧ��ѩӳ÷�Ƶ��顣\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name":         "snow-zhang",       // name of the skill
                        "exp_required": 10000,                  // minimum combat experience required
                                                                // to learn this skill.
                        "jing_cost" :   20,
                        "difficulty":   20,                     // the base int to learn this skill
                                                                // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    80,                     // the maximum level you can learn
                        "min_skill":    20                       // the maximum level you can learn
                                                                // from this object.
                ]) );
        }
}

