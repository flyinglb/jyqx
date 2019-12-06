// zhutou.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("��ͷ", ({ "zhutou","tou" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������ͷ��\n");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 15);
                set("wield_msg", "$Nץ��һ��$n���������е�������\n");
                set("material", "bone");
        }
        init_hammer(1);
        setup();
}

int finish_eat()
{
        if( !query("weapon_prop") ) return 0;
        set_name("�еþ���Ĺ�ͷ", ({ "bone" }) );
        set_weight(150);
        set("long", "�еþ���Ĺ�ͷ��\n");
        return 1;
}
