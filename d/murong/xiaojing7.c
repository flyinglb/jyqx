// /u/beyond/mr/xiaojing7.c
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
Ƭ�����֣�������һ��Сˮ�أ�������һ�����ȡ�
long);
set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"shuichi",
             "north" : __DIR__"liulin2",
             "west" : __DIR__"xiaojing6",
             "south" : __DIR__"cl4",
]));
	setup();
	replace_program(ROOM);
}

