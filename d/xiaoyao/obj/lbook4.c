// lunyu.c ����
inherit ITEM;
void create()
{
        set_name("����", ({ "literateb4", "shu4", "book4"}));
        set_weight(300);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long","һ���׷��ӵġ������\n");
            set("value", 400);
            set("material", "paper");
            set("skill", ([
            "name": "literate",    // name of the skill
            "exp_required": 10, // minimum combat experience required
            "jing_cost":    15,// jing cost every time study this
            "difficulty":  20,// the base int to learn this skill
            "max_skill":  120,// the maximum level you can learn to
            "min_skill":  110,// minimun level required
            ]) );
        }
}
int query_autoload()
{
        return 1;
}
