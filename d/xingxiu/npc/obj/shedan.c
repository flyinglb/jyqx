//  poison: shedan.c
// Jay 3/18/96

// more work needed to use this object to make poison

inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("���ߵ�", ({"shedan", "dan"}));
        set("unit", "ֻ");
        set("long", "����һֻ��ӨӨ�Ķ��ߵ������Ʊ���ҩ��ԭ�ϡ�\n");
        set("value", 800);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        return notify_fail("����������\n");
}

