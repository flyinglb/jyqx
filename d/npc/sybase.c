#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����˹"NOR, ({"Sybase"}));
	set("nickname",MAG"�����ݽ��壪"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
�����½�ӹȺ����II�гɳ����ĸ��֣�Ѹ�ٳ�Ϊ����������
�е�ٮٮ�ߡ�
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
