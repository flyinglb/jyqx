inherit ITEM;

void create()
{
	set_name("��Ҷ", ({ "gold leaf" , "leaf"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ƭ");
		set("long", "����һƬ�����Ľ�Ҷ�ӡ�\n");
		set("value", 10000);
	}
	setup();
}

