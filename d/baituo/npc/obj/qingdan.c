// more work needed to use this object to make poison
inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name("���ߵ�", ({"qing", "qing dan"}));
        set("unit", "ֻ");
	set("long", "����һֻ��ӨӨ�����ߵ������Ʊ����ߵ��ࡻ��ԭ�ϡ�\n");
	set("value", 100);
        setup();
}

int do_eat(string arg)
{
	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        return notify_fail("����������\n");
}
