#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"���"NOR, ({"Fengfeng"}));
        set("nickname",HIB"������"NOR);
        set("gender", "����");
	set("age", 25);
	set("per",28);
	set("long",@LONG
һ�����������߳������˼���������������������
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
