#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"ˮ�ᾧ"NOR, ({"Roujing"}));
	set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+HIM+"���������� "+HIC+"���¸��"NOR);
	set("gender", "Ů��");
	set("age", 25);
	set("per",31);
	set("long",@LONG
ˮ�ᾧ������һ����Ƥ��СŮ����Ƣ��ʱ��ʱ�����õ�ʱ���
�����ˣ�����ʱ����Ū�ˡ������С�ı���Ū��������������
��һ���������õ�Ů���Ŷ��
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
