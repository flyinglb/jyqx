// xiao.c
#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(HIG"������"NOR, ({ "xu xiao", "xiao"}));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������ɵĶ��\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ���ӻ����ͳ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���ػ��\n");
        }
        init_dagger(70);
        setup();
}

