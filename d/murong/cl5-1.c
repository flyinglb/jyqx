// /u/beyond/mr/cl5-1.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ��Ҷ�
��������ȥ����æ���Լ������飬������һ�㵡���������������᷿�������
�����ǳ��ȵ����졣
long);
         set("exits", ([
             "south" : __DIR__"cl5-2",
 "west" : __DIR__"xiangfang2",
             "north" : __DIR__"cl5-0",
             "east" : __DIR__"cl5-3",
]));
set("objects",([
__DIR__"npc/yahuan" : 1,
]));
         setup();
         replace_program(ROOM);
}

