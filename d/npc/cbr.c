
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"�ϱ�"NOR,({"Cbr"}));
	set("nickname", HIG"��"HIW"��"HIY"��"HIG"��"HIM"����"HIW"��Ӱ "BLINK+HIR"����"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����ǽ�ӹȺ��MUD�������������ʵ���������˵����cbr��\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
