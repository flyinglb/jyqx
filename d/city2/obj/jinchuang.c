// jinchuang.c ��ҩ

inherit ITEM;


void setup()
{}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_devour", "devour");
}

void create()
{
        set_name(HIY"��ҩ"NOR, ({"jinchuang yao", "jinchuang", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ʿ�ر��Ľ�ҩ��\n");
                set("value", 5000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
        if (me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        if ((int)me->query("eff_qi") == (int)me->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
        else {
                me->receive_curing("qi", 50);
                message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", me);
                me->start_busy(2);
                destruct(this_object());
                return 1;
        }
}

int do_devour(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");

        this_player()->add("combat_exp", 100000);
        this_player()->add("max_neili", 500);
        this_player()->add("max_jingli", 100);
        this_player()->add("potential", 10000);
        message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", this_player());
        destruct(this_object());
        return 1;
}

