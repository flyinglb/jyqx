#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"������"NOR, ({"Cqcq"}));
	set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+HIB+"���� "+HIY+"�޷�����"NOR);
	set("gender", "����");
	set("age", 35);
	set("per",29);
	set("long",@LONG
�������ˣ����½�ӹȺ����II�ڶ���Ϊ���������ң����ɷ������
���֣���ܿ�����һ�����֣���Ϊ�������ɻ�Ծ����̶�Ĵ�����
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
