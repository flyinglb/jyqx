#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"ī��"NOR, ({"Mok"}));
        set("nickname",HIR"��"HIW"����¥"HIR"��"BLK" Ӱ�Ӵ̿�  "HIB"����Ǭ��"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
��һ������ʲô��û���¡�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
