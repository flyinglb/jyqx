#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�ɾ�"NOR, ({"Qibao"}));
        set("nickname",HIR"��Ѫɽׯ "HIW"�� "BLINK+HIC"��ׯ�� ̫���ں���"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",28);
	set("long",@LONG
��˵�������ٶ���죬������һ�������񻰡���
����Ϊ�����ˡ���ʱ���ܹ�ɱ�� 4674 ���ˣ������� 0 ����������ҡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
