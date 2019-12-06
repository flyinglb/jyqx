#include <ansi.h>

inherit NPC;

void create()
{
        set_name("博尔忽", ({ "borhu" }) );
        set("title", YEL"四骏"NOR);
        set("gender", "男性");
        set("age", 54);
        set("per", 20);
        set("long",
"他是成吉思汗早期的朋友和功臣，号称“四骏”之一。\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
