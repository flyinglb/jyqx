#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"剑无影"NOR, ({"Szb"}));
	set("nickname",HIG"〖"HIR+BLINK"血影门"NOR+HIC"〗"HIM"门主·"HIG"鸳"HIY"鸯剑"NOR);
	set("gender", "男性");
	set("age", 32);
	set("per",26);
	set("long",@LONG
他就是〖血影门〗的创始人，喜欢在这里聊天，比武。他认为mud里应
该是感情第一，武功第二。是一个只羡鸳鸯不羡武的玩家，认为在这里的
最爱是风铃(tianxiawudi)，并愿意和她一直在本mud快活的游戏下去。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
