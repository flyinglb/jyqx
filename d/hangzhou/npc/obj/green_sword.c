// green_sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIG"���̽�"NOR, ({ "green_water_sword", "jian" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ͨ�徧Ө��͸�Ľ������䵱����֮����\n");
                set("value", 4000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
        init_sword(100);
        setup();
}
