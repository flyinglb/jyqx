#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����"NOR, ({"Yeah"}));
	set("nickname",HIR"�Ĵ�Ѳ��֮"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
���������½�ӹȺ����II�еڶ������ֵĴ������������
Ҳ������ʦ����Ϊ��̶������Ϥÿһ����������
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
