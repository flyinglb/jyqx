#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��Ѫ"NOR, ({"Chz"}));
        set("nickname",HIR"��"HIW"����¥"HIR"��"HIC"��绤�� ����"HIW"�ǳ�"NOR);
        set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
�Ժð��� �������ʵ� ����� �������������� 
���������˺������� ��ֻ�ý����뻰������ 
��MUD��Ѱ�Ρ�������
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
