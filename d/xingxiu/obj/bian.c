// bian.c ��

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("���", ({ "bian", "yangbian","whip" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ����ޣ������ֲڡ�\n");
                set("value", 30);
                set("material", "leather");
                set("wield_msg", "$N��ৡ���һ����������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������\n");
        }
        init_whip(5);
        setup();
}

