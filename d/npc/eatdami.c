#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�Դ���"NOR, ({"Eatdami"}));
	set("nickname",HIR"ϵͳ����"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long", 
		"�������½�ӹȺ����II��ϵͳ�����ˡ�\n");
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
