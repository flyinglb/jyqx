// Room: /u/mei/room24.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "ʯ��С��");
        set("long", @LONG
��·�趸��һ������ʯ��֮������������ֻ������ɭɭ��������ˡ�
·������һ�Ѱ׹ǣ������й�����ҫ��������౦ʯ����
LONG
        );
    if (random(10)>7)
        set("objects", ([ 
        __DIR__"obj/zhu" : 1,
        __DIR__"obj/zuanshi" : 1,
        __DIR__"obj/feicui" : 1,
        __DIR__"obj/skeleton" : 1,
]));
        set("no_new_clean_up", 0);
        set("outdoors", "room24");
        set("exits", ([ 
  "south" : __DIR__"room23",
  "westup" : __DIR__"room25",
]));

        setup();
        replace_program(ROOM);
}
