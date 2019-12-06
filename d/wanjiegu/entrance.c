// Room: /t/wanjiegu/entrance.c

inherit ROOM;

void create()
{
        set("short", "��ɭ��");
        set("long", @LONG
�����Ǻô�һ��ɭ�֣���ѹѹ��һƬ�������ߡ����ر�������
һ�Ų����ž�������������ÿ�������������ơ����²ݴ�ï�ܣ�
��ס��ȥ·��
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"shan_road4",
        ]));
        set("no_clean_up", 0);

        set("item_desc", ([ /* sizeof() == 2 */
            "�ݴ�" : "һƬï�ܵĲݴԣ���������Ű�������(pushaside)��\n",
            "grass" : "һƬï�ܵĲݴԣ���������Ű�������(pushaside)��\n",
        ]));

        setup();
}

void init()
{
        add_action("do_push","pushaside");
}

int do_push(string arg)
{
        if( !arg ) return 0;
        if( arg != "�ݴ�" && arg != "grass" ) return 0;
        if( arg == "�ݴ�" || arg == "grass" ) {
            message_vision("$N�������ݣ����ϳ���һ����\n", this_player() );
            set("exits/enter", __DIR__"tree_hole");
            call_out("close_passage", 10);
            return 1;
        }
}

void close_passage()
{
//        object room;

        if( !query("exits/enter") ) return;
        delete("exits/enter");
        message("vision","һ��紵�������ݽ�������ס�ˡ�\n", this_object() );
}

