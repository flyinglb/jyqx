#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�ֻ�"NOR, ({"Again"}));
        set("nickname",HIY"��"HIR"��ħ��"HIY"��"BLK"ʹ�� "HIR"а"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
��а��û�зֱ�ֻ����Ϊ�����µ��˶��ˣ��Ż����˺��˺ͻ��ˡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
