// Room: /d/shaolin/guangchang1.c
// Date: YZC 96/01/19

inherit ROOM;

void init();
int close_gate();
int do_open();
string look_gate();

void create()
{
    set("short", "�㳡");
    set("long", @LONG
������������ǰ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊ
ƽ̹�����������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г�
�˳������㳡��Χ�������ܵ������֣��Ľ��ϸ����˼���ʯ����
�ּ�����Ϊģ������ǰ����ǽ���ߣ��������ݣ�����һ��������
���������ߵ����ɼľ��ͭ����(gate)���Ϸ�һ����ң�����
��������š������¡��������֡���ǰ����������վ�ż���ɮ�ˡ�
LONG );
    set("exits", ([
        "east" : __DIR__"guangchang1e",
        "south" : __DIR__"shijie11",
        "west" : __DIR__"guangchang1w",
    ]));

    set("outdoors", "shaolin");
    set("item_desc",([
        "gate"        :    (: look_gate :),
    ]));
    set("objects",([
        CLASS_D("shaolin") + "/qing-fa" : 1,
    ]));
//    set("no_clean_up", 0);
    setup();
    "/clone/board/shaolin_b"->foo();
}


/* TODO
 �˴���Ϊ��(knock gate) ���ź�һɮ��Ӧ���򿪴��ţ�
��֨����һ�������Ŵ��˿�����һλ׳��ɮ���������´�������
���������������� һ�ᣬ
����Ϊ����ɮ�ˣ����������������߻��������������ÿ���˵����ʦ�������ˣ������
����Ϊ����ɮ�ˣ����񽵵ͻ��и��񣩳���������˵��������Ժ������ʹ��ʦ��ʦ�ֻ�
����������������������������������������������������ȥ����Ժ�������й�����
������������������������������������ֱ���ͽ�����Ժ���β��ʺ󣬴���ɮ���Ѻ����
����Ǳ���ɮ�ˣ����ԣ�������˵������λʩ����ذգ����²��Ӵ����ˡ�
����Ǳ���ɮ�ˣ�Ů�ԣ�������˵������λŮʩ��������ذգ����´Ӳ��Ӵ�Ů�͡�
����Ǳ���ɮ�ˣ�������Ů���и�����ʱ������ֿ��һ��ѩ���Ľ䵶���������λε�
���������������������������������������׼����ؿڣ���üŭĿ��˵�������аħ
����������������������������������������������ҹ������Ժ��ٸ��߽�����һ����
��������������������������������������ʱ��ն�����ǵĹ��ȣ�
�Բ����׼ҵ��Ӳ�����������
 */
void init()
{
    add_action("do_knock", "knock");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"smdian")) )
        room = load_object(__DIR__"smdian");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n",
            this_object());
        room->delete("exits/south");
        if (objectp(present("qingguan", room)))
            message("vision", "�����ǰ�Ѵ��Ź���������\n", room);
        else
            message("vision", "׳��ɮ����ǰ�Ѵ��Ź���������\n", room);
    }
    else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/north"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "gate" && arg != "north"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!( room = find_object(__DIR__"smdian")) )
        room = load_object(__DIR__"smdian");
    if(objectp(room))
    {
        set("exits/north", __DIR__"smdian");
        message_vision("$N������������ţ�ֻ��֨��һ����"
            "һλ׳��ɮ��Ӧ���򿪴��ţ�\n"
            "����������Ŀ���������´�����$N��\n",
            this_player());
        room->set("exits/south", __FILE__);
        message("vision", "���洫��һ����������׳��ɮ��Ӧ����ǰ�Ѵ��ſ���\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
    if ( dir != "north" )
    {
        return ::valid_leave(me, dir);
    }

    if (!::valid_leave(me, dir))
        return 0;

    if ( (me->query("family/family_name") == "������"))
    {
        if (me->query("class") != "bonze")
        {
            return notify_fail("׳��ɮ��˵�����Բ����׼ҵ��Ӳ����������С�\n");
        }

        if (((int)me->query("guilty") == 0) && ((int)me->query("K_record") ==
            ((int)me->query("PKS") + (int)me->query("MKS"))))
        {
            write("׳��ɮ�˲����ÿ���˵����ʦ�������ˣ������\n");
            return 1;
        }
        else
        {
            if((int)me->query("guilty") == 0) {
                if((int)me->query("shen_record") > (int)me->query("shen"))
                    me->set("guilty", 1);
                else
                    me->set("guilty", 2);
                me->set("K_record", me->query("PKS") + me->query("MKS"));
                me->set("shen_record", me->query("shen"));
            }

            me->move(__DIR__"smdian");
            return notify_fail("׳��ɮ�˳���������˵��������Ժ������ʹ��ʦ��ʦ��\n"
                "����ȥ����Ժ�������й�����\n");
        }
    }
    else if( present("yingxiong ling", me) || wizardp(me) )
    {
        write("׳��ɮ�˺�ʮΪ�񣬲����ÿ���˵����ԭ���ǹ�ͼݵ�����������\n");
        return 1;
    }
    
    if (me->query("shen") >= 0)
    {
        if (me->query("gender") == "Ů��")
        {
            return notify_fail("׳��ɮ��˵������λŮʩ��������ذգ�"
                "���´Ӳ��Ӵ�Ů�͡�\n");
        }
        else
        {
            return notify_fail("׳��ɮ��˵������λʩ����ذգ����²��Ӵ����ˡ�\n");
        }
    }

    return notify_fail("׳��ɮ����ʱ������ֿ��һ��ѩ���Ľ䵶���������λε�\n"
		"�����׼����ؿڣ���üŭĿ��˵�������аħ������������ҹ�����\n"
		"�Ժ��ٸ��߽�����һ��������ʱ��ն�����ǵĹ��ȣ�\n");

}

string look_gate()
{
    return "һ���������ߵ����ɼľ��ͭ���š�\n";
}
