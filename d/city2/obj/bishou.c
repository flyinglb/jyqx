// bishou.c ذ��

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIR "ذ��" NOR, ({ "bishou","sword" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "ϸ����ذ�ף�������ī���ް�����\n");
		set("value", 50000);
		set("material", "steel");
//              set("no_drop", "�������������뿪�㡣\n");
//              set("no_give", "�����������ܸ��ˡ�\n");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������У�ֻ��һ�ɺ������������\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʣ�ֻ���͵�һ�����졣\n");
	}
	init_sword(200);
	setup();
}
