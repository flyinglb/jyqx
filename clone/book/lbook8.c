// lbook8.c

inherit ITEM;
void create()
{
        set_name(HBBLU+HIC"金庸全集"NOR, ({ "literateb7", "shu7", "book7" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long","新金庸群侠传终极读物。\n");
                set("value", 8800000);
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",      // name of the skill
                        "exp_required": 1000,      // minimum combat experience required
                        "jing_cost":    10,      // jing cost every time study this
                        "difficulty":   15,      // the base int to learn this skill
                        "max_skill":    499,      // the maximum level you can learn
                        "min_skill":    400,      // the maximum level you can learn
                ]) );
        }
}
int query_autoload()
{
   return 1;
}
