#include <ansi.h>

inherit NPC;

void create()
{
        set_name("木华黎", ({ "muhuali" }) );
        set("title", YEL"四骏"NOR);
        set("gender", "男性");
        set("age", 47);
        set("per", 18);
        set("long",
"他是成吉思汗帐前少有的猛将，号称“四骏”之一。\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
