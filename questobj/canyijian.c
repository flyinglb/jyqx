// chanyijian.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("����", ({ "chanyi jian","jian" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������������������\n��˵���˽������Լ����ʱ���Լ������о����������㷢��ʱ���Ѿ����ˡ�\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N��ಡ���һ����֪���Ķ����һ�����������$n�������С�\n");
		set("unwield_msg", "$N�����е�һ��$n��ʧ����Ӱ���١�\n");
            set("dynamic_quest", "/d/wuguan/npc/zhang-yufeng");
	}
	init_sword(450);
	setup();
}
