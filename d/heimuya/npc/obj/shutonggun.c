// shutonggun.c

#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("��ͭ��", ({"shutong gun", "club"}));
	set_weight(2000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ʮ��������ͭ����\n");
		set("value", 1000);
		set("material", "bamboo");
		set("wield_msg", "$N���ִ������һ����ͭ����\n");
		set("unwield_msg", "$N������һ�ۣ�����ͭ���������\n");
	}
	init_club(30);
	setup();
}
