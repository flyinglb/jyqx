// thousand.c

inherit MONEY;

void create()
{
        set_name(HIG"һǧ����Ʊ"NOR, ({"thousand-cash", "thousand-cash_money", "cash"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "thousand-cash");
                set("long", "һ�����ֵһǧ�����ӵ���Ʊ��\n");
                set("unit", "��");
                set("base_value", 100000);
                set("base_unit", "��");
                set("base_weight", 3);
        }
        set_amount(1);
}

