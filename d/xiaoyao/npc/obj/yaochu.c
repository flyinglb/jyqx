// yaochu.c ҩ��

inherit ITEM;

void create()
{
        set_name("ҩ��", ({ "yao chu", "chu", }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ҩ�õĳ�ͷ��\n");
        set("value", 0);
	}
}

