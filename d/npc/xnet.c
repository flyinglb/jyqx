#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"������"NOR, ({"Xnet"}));
        set("nickname",HIC"��"HIY"��������"HIC"��"HIW"��� "HIM+BLINK"�绪����"NOR);
        set("gender", "Ů��");
	set("age", 25);
	set("per",29);
	set("long",@LONG
�������ٸ�����Ψһ�ļ̳��ˣ����޹°��ľ�����Ů��һ��ħ��--ս���˵Ľ��ޡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
