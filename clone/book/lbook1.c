// lbook1.c

inherit ITEM;
void create()
{
        set_name(CYN"���־�"NOR, ({ "literateb1", "shu1", "book1" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long","�����˱ض������־���\n");
                set("value", 50000);
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",      // name of the skill
                        "exp_required": 10,      // minimum combat experience required
                        "jing_cost":    10,      // jing cost every time study this
                        "difficulty":   15,      // the base int to learn this skill
                        "max_skill":    49,      // the maximum level you can learn
                        "min_skill":    20,      // minimun level required
                ]) );
        }
}
