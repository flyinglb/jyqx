#include <ansi.h>

inherit NPC;

void create()
{
        set_name("察合台", ({ "chahetai" }) );
        set("title", CYN"二王子"NOR);
        set("gender", "男性");
        set("age", 27);
        set("per", 22);
        set("long",
"他是成吉思汗的次子，随父东争西讨，勇冠三军。\n");
        set("combat_exp", 5000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
