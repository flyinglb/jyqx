inherit ITEM;

void create()
{
	set_name("����", ({ "budai", "dai", "bag" }));
	set_weight(500);
	set_max_encumbrance(1000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һֻ���鲼֯�ɵĴ��ӣ��������װ������\n");
		set("value", 100);
	}
}

int is_container() { return 1; }
