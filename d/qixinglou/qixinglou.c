// Room: qixinglou.c

inherit ROOM;

void create()
{
        set("short", "����¥");
        set("long", @LONG
����������¥���õĴ��ţ����������ҿ������ǽ���ȥ�������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "out" :"/d/huanghe/caodi2",
            "enter" : __DIR__"dating1",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([ /* sizeof() == 2 */
            "����":"����¥���õĴ��š�\n",
             ]));

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
