// biyujian ����

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIG"����"NOR,({ "biyu jian", "biyu", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set("treasure",1);
                set("material", "steel");
                set("long", "���ǰ����ɵı�����������������͸������֮�⣬��������ޱȡ�\n");
                set("wield_msg", HIC "ֻ�������ˡ���һ�����ڹ����֣�$N��������µ�$n$N���ñ�ֱ��\n" NOR);
                set("unwield_msg", HIC "���񽣻���һ������֮�⣬��ৡ��ط��뽣�ʡ�\n" NOR);
                set("unequip_msg", HIC "���񽣻���һ������֮�⣬��ৡ��ط��뽣�ʡ�\n" NOR);
        }
init_sword(200);
        setup();
}

