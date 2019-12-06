#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"黄百家"NOR, ({"Robin"}));
	set("nickname",HIY"特级大笨蛋"NOR);
	set("gender", "男性");
	set("age", 35);
	set("per",29);
	set("long",@LONG 
是乃明末清初“梨洲先生”黄宗羲之幼子，清入关战乱后结
识武当王征南学武，为武当内家嫡传，有《内家拳经》、《长拳
十段锦》等武学著作，至雍正年间在北京与江南甘凤池并称“南
北大侠”。曾入官至内阁学士，为《明史》撰稿人之一。后为寻
觅昔日红粉知己隐退山野，常人不知其踪，皆以为化仙而去也。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
