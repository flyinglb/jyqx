#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����Ʈ"NOR, ({"Byp"}));
	set("nickname",HIW"ɱ���"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
�������½�ӹȺ����II����Ҫ��������ˡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
