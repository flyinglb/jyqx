#include <ansi.h>

inherit NPC;

void create()
{
        set_name("窝阔台", ({ "wokuotai" }) );
        set("title", CYN"三王子"NOR);
        set("gender", "男性");
        set("age", 24);
        set("per", 26);
        set("long",
"他是成吉思汗的三子，敦厚待人，后来继承了蒙古王位。\n");
        set("combat_exp", 5000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
