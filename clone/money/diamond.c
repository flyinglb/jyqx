// diamond.c

#include <ansi.h>
inherit MONEY;
void create()
{
        set_name(HIC"��ʯ"NOR, ({"diamond", "zuanshi", "diamond_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "diamond");
                set("long", "����������ʯ���˼��˰�����ʯ����������ʯ��\n");
                set("unit", "Щ");
                set("base_value", 10000000 );
                set("base_unit",HIW "����" NOR);
                set("base_weight", 5);
        }
        set_amount(1);
}

