// bamboo_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��",({ "zhujian", "jian", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "bamboo");
                set("long", "����һ����ϰ�����õ��񽣡�\n");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(5);
        setup();
}

