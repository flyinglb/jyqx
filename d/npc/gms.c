#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"Ѫõ��"NOR, ({"Gms"}));
        set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+HIM+"�ϵ绤�� "+BLINK+HIG+"ܷܷ��Ů"NOR);
        set("gender", "Ů��");
	set("age", 25);
	set("per",28);
	set("long",@LONG
������MUD�ﴫ˵�����ٶ���������ң�
����MUD�����������˵����֮һ����
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
