#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��ɳ"NOR, ({"Winds"}));
	set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+HIG+"��ɷ������ "+HIY+"��ɳ����"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",28);
	set("long",@LONG
������������������ң�Ҳ�Ǻ���˵������ҡ���
ͬʱ����Ҳ��һ��һ��ֻ��ˮ�ᾧ�����׺��Ϲ�������
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
