#include <ansi.h>

inherit NPC;

void create()
{
        set_name("拙赤", ({ "zhuochi" }) );
        set("title", CYN"大王子"NOR);
        set("gender", "男性");
        set("age", 32);
        set("per", 24);
        set("long",
"他是成吉思汗的长子，曾经被人怀疑不是成吉思汗的亲生。\n");
        set("combat_exp", 5000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
