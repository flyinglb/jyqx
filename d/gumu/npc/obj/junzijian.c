// junzijian.c
// By Lgg,1998.9

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIC "���ӽ�" NOR, ({ "junzijian", "jian", "sword" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ڱ���ͨ�ڵĽ����������ý�˿���ż����֣�\n"
                            "ǫǫ���ӣ���������\n");
                set("value", 12000);
                set("material", "steel");
                set("weapon_prop/personality", 24);
                set("wield_msg", "$N��̾һ������$n����������ʡ�\n");
                set("unwield_msg", "$N����һ�Σ�$n��Ȼ���ʡ�\n");
        }
        init_sword(35);
        setup();
}
