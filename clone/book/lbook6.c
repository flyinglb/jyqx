// lbook3.c

inherit ITEM;
void create()
{
        set_name(HIM"��ѧ"NOR, ({ "literateb5", "shu5", "book5" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long","�����˱ض��Ĵ�ѧ��\n");
                set("value", 2500000);
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",      // name of the skill
                        "exp_required": 1000,      // minimum combat experience required
                        "jing_cost":    10,      // jing cost every time study this
                        "difficulty":   15,      // the base int to learn this skill
                        "max_skill":    299,      // the maximum level you can learn
                        "min_skill":    200,      // the maximum level you can learn
                ]) );
        }
}
int query_autoload()
{
   return 1;
}
