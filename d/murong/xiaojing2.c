// /u/beyond/mr/xiaojing2.c
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
��׺�����С�������ʯ���ϣ�ž�žવķ���������������������ȥ����
��ӡ�
long);
         set("ourdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaojing1",
             "northwest" : __DIR__"tingyuju",
]));
	setup();
	replace_program(ROOM);
}

