// Room: /u/mei/room38.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
#include <room.h>
void init();
int do_pull(string arg);
int do_climb(string);
int do_move(string);
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
��ǰͻȻ������ֻ��һ�������������ʮ�ɸߴ��ıڷ������������������
��֮������һ�����ң��������꽨�������������Ȼ���ߣ��ڷ��ж�׼λ�ã���
����ɡ�ʯ�������񴲡����������Σ�����̵����Ǿ��£�����б����һ�ߺ��ǡ�
ʯ��һ�ǣ�����һ��һС�����ߺ��ǡ�
LONG
    );
        set("objects", ([ 
  __DIR__"obj/skeleton" : 3,
]));
    set("exits", ([ 
       "east" : __DIR__"room37",

    ]));

    set("item_desc", ([
        "����" : 
"    Բ�����������ʯ�е�̳����ģ����ڵ��ϣ�Բ������̵���һȺ������
��ķ����գ����Ƽ�ϸ���̹����Ǿ��£�Ȼ�����յ�ͷ������ȴ��������һ��
�����뿪��һ�߶�λ�á�\n", 
        "��" :
"    һ����ʯ��̳����Ĵ���\n",    
])); 

    create_door("east", "Сʯ��", "west", DOOR_CLOSED);
    setup();
}
void init()
{
    add_action("do_climb","climb");
    add_action("do_move","move");
}

int do_climb(string arg)
{
    if ( !arg || arg!="��" )
        return notify_fail("��Ҫ�������\n");
    if (this_player()->query_temp("marks/��1"))
        return notify_fail("���Ѿ��������ˡ�\n");

    message_vision("$N�������񴲡�\n",this_player());
    this_player()->set_temp("marks/��1", 1);
        return 1;
}
int do_move(string arg)
{
        object me;
        object room;
        me = this_player();
    if (!arg || arg !="����"){
        write("��Ҫ�ƶ�ʲô��\n");
        return 1;
    }
    if (!me->query_temp("marks/��1") ){
        write("��Ҫ�ƶ�ʲô��\n");
        return 1;
    }

    if (!( room = find_object(__DIR__"room39")) )
            room = load_object(__DIR__"room39");
    this_player()->delete_temp("marks/��1");
    if (!query("exits/enter")){
            set("exits/enter", __DIR__"room39");
            message_vision("$N��Բ�����ػ���������ʹ����̵����յ�ͷ����������һ������¶��һ�����ڡ�\n",me);
            room -> set("exits/out", __FILE__);
            message("vision", "���洫��һ���ƶ�ʯ�ŵ�¡¡��������\n",room);
            call_out("close_door",10);
            return 1;
    }
        write("��Ҫ�ƶ�ʲô��\n");
        return 1;
}
void close_door()
{
        object room=find_object(__DIR__"room39");
        if (!room)
        room = load_object(__DIR__"room39");
        delete("exits/enter");
        message("vision","�������غ�¡һ���ƻ���ԭ���������ֱ���ס�ˡ�\n",this_object());
        room -> delete("exits/out");
        message("vision","���洫��һ�����죬���ڱ���ס�ˡ�\n", room);
}
