//longxiang_book.c ������ܸ

inherit ITEM;

void create()
{
        set_name(HIY"������ܸ"NOR, ({ "longxiang_book" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
//                set("no_drop",1);
                set("long",
                        "ѧ�����������\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name":         "longxiang",            // name of the skill
                        "exp_required": 10000,                  // minimum combat experience required
                                                                // to learn this skill.
                        "jing_cost" :   30,
                        "difficulty":   30,                     // the base int to learn this skill
                                                                // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    199,                    // the maximum level you can learn
                        "min_skill":    0                       // the maximum level you can learn
                                                                // from this object.
                ]) );
        }
}
int query_autoload() { return 1; }

