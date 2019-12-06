// Room: /t/wanjiegu/grassland.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
����һ��Ƭ�ݵأ�ǰ��һ��������ס��ȥ·��ֻ��һ�������
������������������һƬ�����Ű��ᣬд�žŸ����֣����ն�
����˹�ɱ���⡱�����Ϲ���һ��������
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 1 */
            "enter" : __DIR__"tunnel2",
        ]));
        set("no_clean_up", 0);

        set("item_desc", ([ /* sizeof() == 2 */
            "����" : "һ������������������(knock)������\n",
            "hammer" : "һ������������������(knock)������\n",
        ]));

        setup();
}

void init()
{
        add_action("do_knock","knock");
}

int do_knock(string arg)
{
        if( !arg ) return 0;
        if( arg != "��" && arg != "duan" ) return 0;
        if( arg == "��" || arg == "duan" ) {
        message_vision("$N���������ڵڶ����֡��Ρ�������һ�¡�\n", this_player());
        message_vision("ֻ����������Ӧ��һ���������ˣ���\n", this_player() );
        message_vision("���˴����潫�Ŵ��ˡ�\n", this_player() );
        set("exits/north", __DIR__"xiaoting");
        call_out("close_passage", 10);
        return 1;
        }
}

void close_passage()
{

        if( !query("exits/north") ) return;
        delete("exits/north");
        message("vision","�ű��˹����ˡ�\n", this_object() );
}
