#include <ansi.h>

inherit NPC;

void create()
{
        set_name("速不台", ({ "subutai" }) );
        set("title", BLU"四狗"NOR);
        set("gender", "男性");
        set("age", 43);
        set("per", 16);
        set("long",
"他是成吉思汗军中立过汗马功劳的大将，号称“四狗”之一。\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
