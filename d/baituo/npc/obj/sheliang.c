// sheliang.c ����

inherit ITEM;

void create()
{
        set_name("����", ({ "she liang", "liang", }));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��������\n");
        set("value", 0);
	}
}

