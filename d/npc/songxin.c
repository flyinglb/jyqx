#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�¶�"NOR, ({"Songxin"}));
        set("nickname",HIR"��"HIW"����¥"HIR"�� "HIM"Ѹ�׻��� "HIY"�·����"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
����һ������������ĥ����ң��������ٶ�Ҳ�ܿ죬
ƽʱ����þͰ������ˣ����Ƿ������͡���
�������ر�ļǳ������˻����ٵ���Ϊ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
