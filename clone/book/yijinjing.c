// yijinjing.c

inherit ITEM;
#include <ansi.h>

void dest_self()
{
        write("似乎你觉得忘了什么重要的东西，但你没去在意。\n");
        destruct(this_object());
}

void create()
{
        set_name(YEL"易筋经"NOR, ({ "yijin-jing" }));
        set_weight(300);
        if( clonep() ) {
                if( sizeof(filter_array(children(__FILE__),(: clonep :))) > 1 )
                        call_out((: dest_self :),1);
                set_default_object(__FILE__);
        } else {
                set("unit", "卷");
                set("long",
                "易筋经\n"
                "这是一卷古朴丝织经轴，看来很有年月了，上面文字坚深，不知你识
也不识。易筋经是少林镇寺之宝 ，一直妥藏此处。\n");
                set("value", 10);
                set("no_npc",1);
                set("no_put",1);
                set("no_pawn",1);
                set("no_sell",1);
                set("location",({"/d/shaolin/cjlou1"}) );
                set("material", "silk");
                set("skill", ([
                        "name":         "yijinjing",    // name of the skill
                        "exp_required": 100000, // minimum combat experience required
                        "jing_cost":    10,     // jing cost every time study this
                        "difficulty":   30,     // the base int to learn this skill
                        "max_skill":    300     // the maximum level you can learn
                ]) );
        }
}

void owner_is_killed()
{
       destruct(this_object());
}
