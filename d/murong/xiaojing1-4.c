// /u/beyond/mr/xiaojing1-4.c
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
��׺�����С�������ʯ���ϣ�ž�žવķ�������������������һ��С�ء�
long);
         set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"fenmu",
             "west" : __DIR__"xiaojing1-3",
             "north" : __DIR__"guanxingtai",
]));
set("objects",([
__DIR__"npc/deng" : 1,
]));
	setup();
	replace_program(ROOM);
}

