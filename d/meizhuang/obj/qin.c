// qin.c
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"��������"NOR, ({ "yao qin", "qin"}));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ð������ɵ����١�\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N�ӱ���$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�Żر���\n");
        }
        init_sword(100);
        setup();
}

