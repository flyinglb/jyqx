#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����"NOR, ({"Xyz"}));
	set("nickname",HIC"���ҽ���"NOR);
	set("gender", "Ů��");
	set("age", 35);
	set("per",30);
	set("long",@LONG
�����½�ӹȺ�����е�һ������������һ�ģ��������Ѿ�������
������������������������100�Ķ���������
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
