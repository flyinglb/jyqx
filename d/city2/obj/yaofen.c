// yaofen.c ҩ��

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("ҩ��", ({ "yao fen" , "yao", "fen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ר�����˵�ҩ�ۡ�\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	return notify_fail("ֻ��ר���ɶԸ����������ơ����书���˲���Ҫ������ҩ��\n");

}

