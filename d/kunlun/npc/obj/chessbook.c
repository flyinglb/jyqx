// qinpu.c
inherit ITEM;

void create()
{
        set_name("棋弈入门", ({ "chess book" ,"shu" ,"book"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本初级围棋教材。\n");
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

