#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"������"NOR, ({"Never"}));
        set("nickname",HIR"��"HIW"����¥"HIR"�� ϸ�껤�� "HIW"ԩ��·խ"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
�����Բ��Ǹ��֡�
��վ�����ֻ�Ƕ���������ʱ���ϵ�һ�ֿ϶���
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
