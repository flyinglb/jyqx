#include <ansi.h>

inherit NPC;

void create()
{
        set_name("华筝", ({ "huazheng" }) );
        set("title", MAG"公主"NOR);
        set("gender", "女性");
        set("age", 18);
        set("per", 27);
        set("long",
"他是成吉思汗的女儿，与郭靖有青梅竹马之谊。\n");
        set("combat_exp", 3000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
