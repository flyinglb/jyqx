//LUCAS 2000-6-18
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"ѩɽ����"NOR, ({ "swordbook","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ�������ǵĽ����ؼ���������д���ĸ��֡�ѩɽ��������\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name":         "xueshan-sword",       // name of the skill
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

