#include <ansi.h>

inherit NPC;

void create()
{
        set_name("成吉思汗", ({ "chengjisihan", "king"}) );
        set("title", HIC"一代天骄"NOR);
        set("gender", "男性");
        set("age", 53);
        set("per", 25);
        set("long",
"他是人类历史上拥有领土最辽阔的君王，无敌的蒙古铁骑几乎踏遍欧亚大陆。\n");
        set("combat_exp", 500000);
        set("attitude", "piece");
	set("chat_msg", ({
		"\n成吉思汗皱眉道：花刺子模的战事又有些吃紧，看来我需要出兵了。\n"
		"\n成吉思汗大笑道：我现在疆土辽阔，妻妾成群，子孙满堂，自古谁能比得上我？\n"
		"\n成吉思汗长叹道：好久没见到郭靖了，华筝愁得头发都白了。\n"
	}) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 30);
}
