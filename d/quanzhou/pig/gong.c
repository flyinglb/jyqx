inherit ROOM;

void reset();

void create()
{
        set("short", "��������");
        set("long", @LONG
����һ�����������������ڽ�ڻԻͣ���ש���أ������ǽ�������
��ʳ�裬����������������Ե���ʳ����С�ײˡ�ľ�ϡ����ӡ�С��ݡ�
���ܲ�������㣮��
LONG
        );

        set("exits", ([
                "sl" : "/d/shaolin/guangchang1",
                "wn" : "/d/wudang/sanqingdian",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/city/gbxiaowu",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
        ]));
        set("objects", ([
            __DIR__"obj/cleansword" : 1,
            __DIR__"obj/marz" : 1,
            __DIR__"obj/rover" : 1,
            __DIR__"obj/xiang" : 1,
	]));

        set("valid_startroom",1);

        set("outdoors", "quanzhou");
        setup();
}

void init()
{
        add_action("do_leave", "leave");
}

int valid_leave(object me, string dir)
{
        if ((string)me->query("name")!="������"){
                write("����һ�Ѿ�ס�������˵�������ţ���̫�ݣ������ܳ�������\n");
		return 0;
	}
        return ::valid_leave(me, dir);
}

int do_leave()
{
        object me = this_player();
        if(me)
                me->move("/d/wizard/wizard_room");
        return 0;
}
