#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�����"NOR, ({"Shoe"}));
        set("nickname",HIY"��"HIW"Ľ������"HIY"��"HIM" ��С��  "HIW"��������"NOR);
        set("gender", "Ů��");
	set("age", 25);
	set("per",29);
	set("long",@LONG
��˵���ǳ����󱿵��ĽӰࡣ
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
