#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"è��"NOR, ({"Hpph"}));
	set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+HIB+"���� "+HIM+"����è"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
�����½�ӹȺ�����ĵ�������ң������ܿ죬�Ѿ�����һ����
�ֵ����С���Ϊ����ʵ���������ˣ�������������һ�����ˡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
