#include <ansi.h>

inherit NPC;

void create()
{
        set_name("拖雷", ({ "tuolei" }) );
        set("title", CYN"四王子"NOR);
        set("gender", "男性");
        set("age", 21);
        set("per", 27);
        set("long",
"他是成吉思汗的四子，忽必烈的父亲，以外交手段闻名。\n");
        set("combat_exp", 5000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
