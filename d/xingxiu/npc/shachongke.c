//  poison: shachongke.c
// Jay 3/17/96

// more work needed to use this object to make poison

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("ɳ���", ({"shachong ke", "ke"}));
        set("unit", "ֻ");
        set("long", "����һֻɳ��ĸɿǣ����Ʊ���ҩ��ԭ�ϡ�\n");
        set("value", 300);
//        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        return notify_fail("����������\n");
}

