// Room: ehouse2.c

inherit ROOM;

void create()
{
        set("short", "��լ");
        set("long", @LONG
����һ��ܽ�ʵ�ķ��ӣ���ȻҲ�Ǽ��������������ĳ�����ıȴ���
������������Ҫ�úܶࡣǽ�Ϲ��š����°���һЩũ�ߡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south" :__DIR__"eroad2",
        "enter" : "/d/heishou/damen",
        ]) );

        set("objects", ([
                __DIR__"npc/dibao": 1
        ]) );
        set("no_clean_up", 0);

        setup();
}
/*

void init()
{
        add_action("do_want","want");
}

int do_want(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
        if( arg != "ɱ��"  ) return 0;
        if( arg == "ɱ��"  ) {
        message_vision("$N���ŵر���֪��˵��Щʲô��\n ", this_player() );
message_vision("�ر���Cool�ض�$N˵������������ɱ�ˣ����ҶԵط��ˣ������ɣ�\n",this_player() );
        set("exits/enter", "/u/liangbaobao/heishou/damen");
        call_out("close_passage", 3);
        return 1;
        }
}

void close_passage()
{

        if( !query("exits/enter") ) return;
        message_vision("ûǮ��������ɱ�ˣ����˰�,�ر�һ�¾Ͱ��Ź���������\n ", this_player() );
        delete("exits/enter");
}
*/
