#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"Ľ�ݻ��"NOR, ({"Frost"}));
        set("nickname",HIY"��"HIW"Ľ������"HIY"��"HIG" �󵱼ҡ�"HIR"����а��"NOR);
        set("gender", "����");
	set("age", 25);
	set("per",28);
	set("long",@LONG
��һ������ʲôҲû���¡�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
