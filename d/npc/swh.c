
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ˮ�޺�",({"swh"}));
set("nickname",HIM"�鵶��ˮˮ����" NOR);
 
	set("gender", "����");
	set("age", 20);
	set("long", 
		"������������ħ��ˮ�޺ۡ���\n");
	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
