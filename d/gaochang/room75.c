// Room: /d/gaochang/room75.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "ѩ��");
        set("long", @LONG
���������Ǹ߸��������շ壬��������ɼ�ϥ�Ļ�ѩ��
LONG
);

        set("exits", ([ 
  "out" : __DIR__"room63",
]));

        set("objects", ([ 
   __DIR__"obj/xuecan" : 1,
]));

        setup();
        replace_program(ROOM);
}

