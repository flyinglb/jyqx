#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"ս����"NOR, ({"Tiandao"}));
        set("nickname",HIC"��"HIY"��������"HIC"��"BLK"ħ�� "BLINK+HIR"��������"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
��һ������ʲô��û���¡�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
