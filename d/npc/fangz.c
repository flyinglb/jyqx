#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����"NOR, ({"Fangz"}));
        set("nickname",HIR"��"HIW"����¥"HIR"��"HIG"��Ȩ���� "HIY"������ħ"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
�����Ͽɹ󣬰���۸��ߣ���Ϊ���ɹˣ����߽Կ��ס�
���Ǳ�mud�����˵�������֮һ������֪�������˲����ࡣ
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
