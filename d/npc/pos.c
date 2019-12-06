
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"破四"NOR,({"Pos"}));
        set("nickname", HIW"〖 "HIR"铁血山庄"HIW" 〗"HIC"大庄主 "BLINK"铁斧"HIY"铜皮"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
                "俗话说，欲速则不达。但对眼前的这个人却不怎么正确。\n"
                "他以最合适的方法和最快的速度在短时间内跻身于高手之列。\n"
                "只是平时却不苟言笑，练功把他也训练得快成了机器人了。\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
