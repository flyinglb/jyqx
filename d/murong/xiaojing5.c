// /u/beyond/mr/xiaojing5.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"С��"NOR);
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ������������������濴ȥ��һ
Ƭ�����֣�������һ�����ȡ�������С�������졣
long);
set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaojing6",
             "north" : __DIR__"liulin",
             "west" : __DIR__"shiqiao1",
             "south" : __DIR__"cl2",
]));
	setup();
	replace_program(ROOM);
}

