//  instrument: dongbula.c
// Jay 3/18/96

inherit ITEM;
int do_play(string arg);

//void setup()
//{}

void init()
{
        add_action("do_play", "play");
}

void create()
{
        set_name("������", ({"dongbula"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ά�����������������������������(play)����\n");
                set("value", 100);
        }
//        setup();
}

int do_play(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ����ʲô��\n");
        switch( random(3) ) {
                case 0:
                        say(this_player()->name() + "���𶬲���������س�����\n"
"����ңԶ�ĵط�����λ�ù��ÿ�������߹�����ձ������Ҫ����\n"
"�����������\n");
			write(this_player()->name() + "���𶬲���������س�����\n"
"����ңԶ�ĵط�����λ�ù��ÿ�������߹�����ձ������Ҫ����\n"
"�����������\n");

                        break;
                case 1:
                        say(this_player()->name() + "���𶬲��������ֵس�����\n"
"����ǵ�ʯͷԲ��Ӳ����ϴ�����ඣ�����ǵĹ�����ӳ����ֻ�۾���Ư����\n");
			write(this_player()->name() + "���𶬲��������ֵس�����\n"
"����ǵ�ʯͷԲ��Ӳ����ϴ�����ඣ�����ǵĹ�����ӳ����ֻ�۾���Ư����\n");

                        break;
                case 2:
                        say(this_player()->name() + "���𶬲��������˵س�����\n"
"���̲�ϵ�һ����Ȫ����ɽ�ϵ�һ��ѩ�����籩������Զ��ͣ����������ʲôʱ�򰡣�"
"���ܼ������Ц����\n");
			write(this_player()->name() + "���𶬲��������˵س�����\n"
"���̲�ϵ�һ����Ȫ����ɽ�ϵ�һ��ѩ�����籩������Զ��ͣ����������ʲôʱ�򰡣�"
"���ܼ������Ц����\n");

                        break;
        }
        return 1;
}

