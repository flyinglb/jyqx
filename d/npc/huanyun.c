#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��ҹ��"NOR, ({"Huanyun"}));
        set("nickname",HIC"��"HIY"��������"HIC"��"HIW"ʥ�� "HIC+BLINK"�������ң"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
����������ǲ������ˣ������ϵ������������䡭��
���վ������˸����书����Ȼ�����֮�䡭��
�����Ľ����У���֪�Ƿ��ܼ����������۲��ӵ��ˡ���
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
