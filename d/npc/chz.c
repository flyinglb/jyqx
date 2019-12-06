#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"凝血"NOR, ({"Chz"}));
        set("nickname",HIR"【"HIW"七星楼"HIR"】"HIC"清风护法 月醉"HIW"星沉"NOR);
        set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
性好安逸 但穷困潦倒 生活简单 但整天无所事事 
因不能随便对人胡言乱语 而只好将梦想话做文字 
在MUD里寻梦…………
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
