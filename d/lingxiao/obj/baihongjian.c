//LUCAS 2000-6-18
// baihongjian.c �׺罣
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( HIW "�׺罣" NOR , ({ "baihongjian", "sword", "jian" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����������ı���,������������֮����\n");
                set("value", 10000);
                set("material", "steel");
                set("weapon_prop/personality", 8);
                set("wield_msg", "$N��ৡ���һ�����һ������������$n��������,ɲʱ��������,��ľ���ᡣ\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(150);
        setup();
}
