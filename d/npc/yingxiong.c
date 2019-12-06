#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"英雄"NOR, ({"Yingxiong"}));
        set("nickname",HIC"〖"HIR + BLINK+"血影门"+NOR+HIC"〗"+HIM+"副门主·"+HIW+"快乐如风"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",30);
	set("long",@LONG
他就是在金庸群侠MUD里最活跃的人了，他很乐意帮助新人。他手持一把
银白色的英雄剑驰骋江湖，之后创立了自己的帮会「风云山庄」，他一
生逍遥自在，现在仍活跃在江湖上，他也是「风云山庄」的创始人。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
