#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"Ѿ��"NOR, ({"Anf"}));
        set("nickname",HIW"�� "HIR"��Ѫɽׯ"HIW" ��"HIC"ʮ���� "HIY+BLINK"**��**"NOR);
	set("gender", "����");
	set("age", 25);
	set("per",29);
	set("long",@LONG
����һ�����˵��ˣ���һ����mud�ͽ��������ã�
����һ�����ֵ��ˣ�����̶����ʶ�˺ܶ�����ѣ�
����һ���Ҹ����ˣ�����ʵ�ﻹ��mm��飻
������̫~~~~~~��~~~~~��~~~~~��~~~~~~~~
LONG);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}
