#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW "监考老师" NOR,({"jiankao teacher"}));
        set("nickname", BLINK+HIC"可恶的"NOR);
        set("gender", "男性");
        set("age", 30);
        set("long", 
                "他是一个专门抓人作弊的监考老师。\n");

        setup();
        
        carry_object("/d/city2/obj/jinduan")->wear();
}

