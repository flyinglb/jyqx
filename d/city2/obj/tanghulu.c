// tanghulu.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���Ǻ�«", ({ "bingtang hulu", "bingtang","hulu" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ�����ı��Ǻ�«\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 2);
		set("food_supply", 10);
        }
    setup();
}

