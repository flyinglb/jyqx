// caomei.c

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("��ݮ", ({ "cao mei", "mei" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ���ʺ�Ĳ�ݮ��\n");
		set("unit", "��");
		set("value", 5);
		set("food_remaining", 1);
		set("food_supply", 10);
        }
    setup();
}

