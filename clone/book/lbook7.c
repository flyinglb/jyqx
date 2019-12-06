// lbook7.c

inherit ITEM;
void create()
{
        set_name(HBYEL+HIY"古文观止"NOR, ({ "literateb6", "shu6", "book6" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long","读书人必读的古文观止。\n");
                set("value", 5000000);
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",      // name of the skill
                        "exp_required": 1000,      // minimum combat experience required
                        "jing_cost":    10,      // jing cost every time study this
                        "difficulty":   15,      // the base int to learn this skill
                        "max_skill":    399,      // the maximum level you can learn
                        "min_skill":    300,      // the maximum level you can learn
                ]) );
        }
}
int query_autoload()
{
   return 1;
}
