#include <ansi.h>

inherit NPC;

void create()
{
        set_name("合撒儿", ({ "hesar" }) );
        set("gender", "男性");
        set("age", 49);
        set("per", 18);
        set("long",
"他是成吉思汗的弟弟，一生辅佐兄长南征北战。\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
