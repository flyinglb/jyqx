// binv.c 童子
// By Winzip 200.3.8

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("婢女", ({"bi nv", "nv"}));
        set("age", 13);
        set("gender", "女性");
        set("long","她是昆仑山的婢女。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("dex", 18);
        set("combat_exp", 4000);
        set("shen_type", 100);

        set_skill("unarmed", 10);
        set_skill("dodge", 15);
        set_skill("parry", 15);
        set_skill("blade", 10);
        set_skill("force", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 15);
        set_temp("apply/armor", 20);

        setup();
        carry_object("/clone/cloth/female5-cloth")->wear();
}

