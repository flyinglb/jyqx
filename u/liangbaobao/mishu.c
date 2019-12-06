#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW "秘书" NOR,({"mi shu"}));
        set("nickname", BLINK+HIC"宝宝的秘书"NOR);
        set("gender", "女性");
        set("age", 18);
        set("long", 
                "她是一个漂亮温柔的女秘书。\n");

        setup();
        
        carry_object("/d/city2/obj/jinduan")->wear();
}

