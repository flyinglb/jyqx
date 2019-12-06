// fu-woshi.c ����
// By Lgg,1998.10

inherit ROOM;
int do_pull(string arg);

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ�Ա������ң��������������һ�������ӡ�������
��һ�ŵ��Ű��ɹ����Ĵ󴲣���ͷ��һ������(drawer)��������
˿�¶У����Ľ�����������������㲻���������ﰲȻ��˯�ˡ�
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"fu-houyuan",
        ]));
        set("objects", ([
                __DIR__"npc/yuanwai" : 1,
        ]));
        set("item_desc", ([
        "drawer": "һ�����룬���������(pull)������������в��ٽ����鱦Ŷ��\n"
        ]) );

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_pull","pull");
}

int do_pull(string arg)
{
        object me = this_player();

        if( !arg || arg != "drawer" ) {
                return notify_fail("��Ҫ����ʲô��\n");
        }

        message_vision("$N�ѳ�����������û���ü���������ʲô������ֻ���ô���֨֨
������\n",me);
        message_vision("�Զ������߷ֿ����ֳ�һ��������Ķ��ڡ�\n", me);
        set("exits/down", __DIR__"fu-midao");
        remove_call_out("close");
        call_out("close", 5, me);

        return 1;
}

void close(object room)
{
        message("vision","�����ֺ����������Ѷ��ڷ�ס�ˡ�\n", room);
        room->delete("exits/down");
}
