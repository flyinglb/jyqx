// /u/beyond/mr/ytyuan.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIM"ӣ��԰"NOR);
         set("long",@long
����һƬӣ��԰�����Ͽ�����ӣ�һ���
long);
         set("exits",([
"west" : __DIR__"ytyuan2",
             "north" : __DIR__"midao",
             "south" : __DIR__"huandong",
]));
	setup();
	replace_program(ROOM);
}

