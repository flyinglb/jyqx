// gold.c
#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIY"�ƽ�"NOR, ({"gold", "ingot", "gold_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "gold");
                set("long", "�ƳγεĽ��ӣ��˼��˰��Ľ��ӣ����������ӣ�\n");
                set("unit", "Щ");
                set("base_value", 10000 );
                set("base_unit", "��");
                set("base_weight", 37);
        }
        set_amount(1);
}
