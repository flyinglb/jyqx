#include <ansi.h>

inherit NPC;

void create()
{
        set_name("赤老温", ({ "chilaowen" }) );
        set("title", YEL"四骏"NOR);
        set("gender", "男性");
        set("age", 50);
        set("per", 18);
        set("long",
"他是成吉思汗早期的朋友和功臣，号称“四骏”之一。\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
