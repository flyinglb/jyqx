// putuan.c С����

inherit ITEM;

void create()
{
	set_name("С����", ({ "putuan", "pu", "tuan" }));
	set_weight(500);
	set_max_encumbrance(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ͨ��С���š�\n");
		set("value", 100);
	}
}

int is_container() { return 1; }
