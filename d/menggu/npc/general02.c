#include <ansi.h>

inherit NPC;

void create()
{
        set_name("帖木格", ({ "tiemuge" }) );
        set("gender", "男性");
        set("age", 45);
        set("per", 14);
        set("long",
"他是成吉思汗的弟弟，一生辅佐兄长南征北战。\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
