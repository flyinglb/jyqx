// Room: /t/wanjiegu/tree_hole.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ڷǳ���խ�����ߺڰ������������ǿݲݡ�����ǽ����һ
ֻ��֩�����ڱ�֯һ��֩������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "out" : __DIR__"entrance",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([ /* sizeof() == 2 */
            "�ݲ�":"һ�ѿݲݣ�������һ��������(ring)��\n",
            "grass":"һ�ѿݲݣ�������һ��������(ring)��\n",
        ]));

        setup();
}

void init()
{
        add_action("do_pull","pull");
}

int do_pull(string arg)
{
        if( !arg ) return 0;
        if( arg != "������" && arg != "ring" ) return 0;
        if( arg == "������" || arg == "ring" ) {
        message_vision("$N�þ����������������һ��ľ�壬����¶��һ����\n", this_player() );
        set("exits/enter", __DIR__"tunnel1");
        call_out("close_passage", 10);
        return 1;
        }
}

void close_passage()
{

        if( !query("exits/enter") ) return;
        delete("exits/enter");
        message("vision","ľ����˻Σ�������Ķ��ڸ�ס�ˡ�\n", this_object() );
}

