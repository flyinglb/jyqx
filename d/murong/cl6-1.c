// /u/beyond/mr/cl6-1.c
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
��������ȥ����æ���Լ������飬������һ�㵡�������ȶ������᷿�������
�����ǳ��ȵ����졣
long);
         set("exits", ([
             "south" : __DIR__"cl6-2",
 "east" : __DIR__"xiangfang3",
             "north" : __DIR__"cl6-0",
             "west" : __DIR__"cl6-3",
]));
set("objects",([
__DIR__"npc/puren" : 2,
]));
         setup();
         replace_program(ROOM);
}

