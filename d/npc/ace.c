#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��˫"NOR, ({"Ace"}));
	set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+HIB+"���� "+HIW+"������˫"NOR);
	set("gender", "Ů��");
	set("age", 25);
	set("per",28);
	set("long",@LONG
�����Ƿ�����ӵĽ��ޣ��ǵڶ����Ƚ����ڵ�����ˣ�ֻ���м���
�˺ܾã��Ų������������ֵĺ󳾳�Ϊһ�����ˡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
