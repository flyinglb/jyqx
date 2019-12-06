#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"爱学习"NOR, ({"Lovenow"}));
	set("nickname",HIR"☆"+HIC+"吃亏"+HIW+"就是"+BLINK+HIM+"占便宜"+NOR+HIR+"☆"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per",29);
	set("long",@LONG
☆☆☆☆☆☆☆☆☆☆☆☆☆
☆ 你永远不懂我的土，   ☆
☆ 象萝卜不懂人参的补。 ☆
☆☆☆☆☆☆☆☆☆☆☆☆☆
他是金庸群侠传里成长非常快的新一代高手，这得宜于他曾经在泥潭中摸爬滚打三年多的
实战经验。现在他已经处于半隐退状态了，但是只要有机会，他还是会常来光顾的。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
