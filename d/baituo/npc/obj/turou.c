// turou.c

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("����", ({ "tu rou", "rou" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һֻ�տ�����������⡣\n");
		set("unit", "ֻ");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 25);
        }
    setup();
}

