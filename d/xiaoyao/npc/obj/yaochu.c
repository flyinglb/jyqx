// yaochu.c 药锄

inherit ITEM;

void create()
{
        set_name("药锄", ({ "yao chu", "chu", }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把挖药用的锄头。\n");
        set("value", 0);
	}
}

