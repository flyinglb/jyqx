#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�Ϻ���"NOR, ({"Boboy"}));
	set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+HIC+"������ʹ "+HIB+"��������"NOR);
	set("gender", "����");
	set("age", 26);
	set("per",28);
	set("long",@LONG
���������½�ӹȺ����II�ĺ���֮�㣬��̤�ſ����Ĵ���
֮·�����ڳ�Ϊһ�����ˡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
