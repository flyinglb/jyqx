// /u/beyond/mr/midao.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",BLU"�ص�"NOR);
         set("long",@long
�������س�ʪ��ǽ����һ����ѡ�
long);
         set("exits",([
             "south" : __DIR__"ytyuan",
             "north" : __DIR__"hhyuan",
]));
         setup();
	 replace_program(ROOM);
}

