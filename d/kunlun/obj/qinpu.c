// qinpu.c
inherit ITEM;

void create()
{
        set_name("����", ({ "qin pu" ,"pu" ,"book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ף���¼�˲��ֹŶػ͵����֡�\n");
                set("value", 10000);
                set("material", "paper");
                set("skill", ([
                        "name": "music",        // name of the skill
                "exp_required": 100, 
                   "jing_cost": 10,
                  "difficulty": 40,                    // the base int to learn this skill
                   "min_skill": 40,
                   "max_skill": 180,
                             ]) );
        }
}

