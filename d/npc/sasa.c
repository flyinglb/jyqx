
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ӽ��",({"sasa"}));
	set("nickname", HIG "��Ѫ����Ĺ�" NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"��������ϯ��������ӽ������\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
