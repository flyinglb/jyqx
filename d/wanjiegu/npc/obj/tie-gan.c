// tie-gan.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("ϸ����", ({ "tie-gan" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ϸ���ŵ����ˡ�\n");
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���¡�\n");
        }
        init_sword(30);
        setup();
}

