// five.c ��Ҷ

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��Ҷ", ({"five"}));
	set("nickname", GRN"����ɽ��ɽ��ʦ"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����ǰ���ɽ�Ĵ�ʼ�ˡ���Ҷ����\n");
	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
