
#include <ansi.h>

inherit NPC;

void create()
{
         set_name(HIW"����"NOR,({"Yuan"}));
	set("nickname", HIG"��"HIW"��"HIY"��"HIG"��"HIM"����"HIW"��Ӱ "BLINK+HIC"����"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����ǽ�ӹȺ��MUD�������������ʵ���������˵����yuan��\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
