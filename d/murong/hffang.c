// /u/beyond/mr/hffang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",BLU"���ʷ�"NOR);
         set ("long",@long
ʯ�ݺڶ�����, ֻ��һ���˱�����һ����������, ���������˶���, ����
������, ȴ˵�����������ٿ�����ʱ, ֻ��һ��������������������������һ
��ѩ���ĳ���, ����һ����ˮ, ���ֱð������
long);
         set("exits",([
         "east" : __DIR__"hhyuan",
         "west" : __DIR__"cl3-3",
]));
set("objects",([
__DIR__"npc/yan" : 1,
__DIR__"npc/tang" : 1,
]));
	setup();
	replace_program(ROOM);
}

