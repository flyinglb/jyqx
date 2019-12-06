#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"丫包"NOR, ({"Anf"}));
        set("nickname",HIW"〖 "HIR"铁血山庄"HIW" 〗"HIC"十四卫 "HIY+BLINK"**飞**"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
他是一个幸运的人，第一次玩mud就进了名人堂；
他是一个快乐的人，在泥潭里认识了很多的朋友；
他是一个幸福的人，在现实里还有mm相伴；
他真是太~~~~~~高~~~~~兴~~~~~啦~~~~~~~~
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
