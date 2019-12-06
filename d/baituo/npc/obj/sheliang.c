// sheliang.c ÉßÁ¸

inherit ITEM;

void create()
{
        set_name("ÉßÁ¸", ({ "she liang", "liang", }));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°ü");
		set("long", "Ò»°üÉßÁ¸¡£\n");
        set("value", 0);
	}
}

