// qinpu.c
inherit ITEM;

void create()
{
        set_name("��������", ({ "chess book" ,"shu" ,"book"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������Χ��̲ġ�\n");
                set("value", 2000);
                set("material", "paper");
                set("skill", ([
                        "name": "chess",        // name of the skill
                "exp_required": 100, 
                   "jing_cost": 20,
                  "difficulty": 30,                    // the base int to learn this skill
                   "max_skill": 40,
                             ]) );
        }
}

