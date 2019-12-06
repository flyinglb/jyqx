#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"梅云芳"NOR, ({"Yueliang"}));
        set("nickname",HIM"【月亮门】"HIW+BLINK"帮主"NOR+HIR"彩"HIG"虹"HIB"仙"HIY"女"NOR);
	set("gender", "女性");
	set("age", 25);
	set("per",31);
	set("long",@LONG
她的美纯出於自然的鬼斧神功，肩如刀削、腰若绢束、脖颈长秀柔美、皮肤幼滑白、明
眸顾盼生妍、梨涡浅笑，配以云状的发髻、翠绿的簪钗，缀着明珠的武士服，脚踏着小
蛮靴，天上下凡的仙女，亦不外如此。
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
