// qunxing-tu.c
inherit ITEM;

void create()
{
        set_name("Ⱥ����ͼ", ({ "qunxing-tu" ,"tu" ,"book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����д������Ⱥ���˶����顣\n"
                        "���ƺ���û����ô�򵥡�\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
//                      "name":  "beidou-zhen",               // name of the skill
                      "name":  "array",               // name of the skill
              "exp_required":  100,
                 "jing_cost":  10,
                "difficulty":  20,                          // the base int to learn this skill
                 "max_skill":  120
                             ]) );
        }
}

