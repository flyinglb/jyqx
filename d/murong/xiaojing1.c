// /u/beyond/mr/xiaojing1.c
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
��׺�����С�������ʯ���ϣ�ž�žવķ�������������������ȥ������
С�������졣
long);
         set("ourdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaoshe",
             "west" : __DIR__"xiaojing2",
]));
	setup();
	replace_program(ROOM);
}

