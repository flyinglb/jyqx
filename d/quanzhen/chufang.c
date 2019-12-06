// chufang.c ����
// By Lgg,1998.10

inherit ROOM;
int do_kan(string arg);

void create()
{
        set("short", "����");
        set("long", @LONG
������ȫ��̵ĳ������ݽ��϶���һ����ֱ۴�ϸ��ľ�񣬿�
����û�����á�һλ�𹤵�������ü������������������ǶѲ�
ǽ�Ϲ���һ������(paizi)��ǽ������һ�Ѳ񵶡�
LONG
        );
        set("exits",([
                "west" : __DIR__"shantang",
        ]));
        set("item_desc", ([
            "paizi": "���տ����ˣ��������š�\n"
        ]) );
        set_temp("times" , 20);
        set("objects" , ([
                __DIR__"npc/huogong" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object me=this_player();
        object ob;
        if (query_temp("times")==0)
                return notify_fail("����Ļ�����ˣ����������ɣ�\n");

        if (!arg || arg != "��")
                return notify_fail("���ҿ���С�������Ը�����\n");

        if(present("huogong", environment(me)) && living(present("huogong", environment(me))))
        {
        if ( (int)me->query("jing")<50)
                return notify_fail("��ľ��������ˣ���Ϣһ����ٿ��ɡ�\n");

        message_vision("$N����񵶣�����һ����𣬷�������ȥ��\n",me);
	add_temp("times",-1);

        if (random(3)<2) {
                me->receive_damage("jing",20+random(20));
                message_vision("���$N�������ͣ���һ����Ƕ���˲��$N�þ�����
�������Ѳ񵶰γ�������ˤ�˸��������\n",me);
        }
        else {
                me->receive_damage("jing",20+random(40));
                ob = new("/clone/money/silver");
                ob->set_amount(10);
                ob->move(me);
                message_vision("���ľ��Ӧ�����������롣�𹤵���Ц�Ŷ�$N˵���㹤
���Ĳ���ѽ��������ĳ��͡�\n",me);
                message_vision("�𹤵��˸�$NһЩ���ӡ�\n",me);
        }
        return 1;
        }
        else
                return notify_fail("�ϰ嶼�����ˣ���Ϊ˭�׸ɰ���\n");
}

