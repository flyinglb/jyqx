inherit ITEM;

void create()
{
        set_name(HIG "诗经" NOR, ({  "shijing", "shu4", "book4" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本诗经。\n");
                set("value", 1000000);
                set("material", "paper");
                set("skill", ([
                        "name": "literate",
                        "exp_required": 10000,        // minimum combat experience required
                        "jing_cost": 10,        // jing cost every time study this
                        "difficulty":   30,     // the base int to learn this skill  
                        "max_skill":    200,    // the maximum level you can learn
                        "min_skill":    100,      // minimun level required

                ]) );
        }
}

int query_autoload()
{
   return 1;
}

