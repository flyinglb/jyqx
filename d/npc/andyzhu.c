#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����"NOR, ({"Andyzhu"}));
	set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+HIC+"¥�� "+BLK+"ħ��"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
�����½�ӹȺ����II�еڶ��������еĺ�ƽ�����ߣ�Ϊ����̸
���������г��߷緶��
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
