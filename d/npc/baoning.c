#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����"NOR, ({"Baoning"}));
	set("nickname",HIG"�����½�ӹȺ����II�� ֮ "HIR+HBWHT+BLINK"������"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",28);
	set("long",@LONG
���ǵ���������ң������ᣡ���������ˣ�������������ˣ����˺�˧����
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
