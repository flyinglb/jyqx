// Room: qixinglou.c

inherit ROOM;

void create()
{
        set("short", "�콣��");
        set("long", @LONG
�������콣�ŵ���ڡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "out" : "/d/city/guangchang",
        ]));
        set("no_clean_up", 0);

        setup();
}
/*
void init()
{
        add_action("do_kiss","kiss");
}

int do_kiss(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
        if( arg != "���Ǿ���" && arg != "closedoor" ) return 0;
        if( arg == "���Ǿ���" || arg == "closedoor" ) {
        message_vision("$N�����������ô��ţ�һ��СѾ�߰��Ŵ򿪣������㼸�ۣ�С������Ѱ��������ɡ�\n", this_player() );
        set("exits/enter", __DIR__"dating1");
        call_out("close_passage", 3);
        return 1;
        }
}

void close_passage()
{

        if( !query("exits/enter") ) return;
        delete("exits/enter");
        message("vision","����˵������������¥����ô����������ˡ�\n", this_object() );
}
*/
