// doll.c ����

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
	set_name("����", ({"doll"}));
	set("nickname", GRN"�г���Ա"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����������ġ����ʡ�����ӹȺ�������Զ���������ͳ�������֮��\n"
		"������һλ���ȵ����ԣ�����TMN BBS�����İ�����\n");
	setup();

	carry_object("/d/city2/obj/jinduan")->wear();
}
