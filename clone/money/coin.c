// coin.c
#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(YEL"ͭǮ"NOR, ({"coin", "coins", "coin_money" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "coin");
                set("long", "������ͨ�е�λ��С�Ļ��ң�ԼҪһ����ͭ���ֵ��һ��������\n");
                set("unit", "Щ");
                set("base_value", 1);
                set("base_unit", "��");
                set("base_weight", 1);
        }
        set_amount(1);
}

