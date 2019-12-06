#include <ansi.h>

inherit NPC;

void create()
{
        set_name("哲别", ({ "zhebie" }) );
        set("title", BLU"四狗"NOR);
        set("gender", "男性");
        set("age", 39);
        set("per", 26);
        set("long",
"他是成吉思汗军中有名的神箭手，号称“四狗”之一。\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
