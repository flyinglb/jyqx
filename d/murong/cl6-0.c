// /u/beyond/mr/cl6-0.c
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
��������ȥ����æ���Լ������飬������һ�㵡�������ȶ������鷿��������
���ȵ����졣
long);
         set("exits", ([
             "south" : __DIR__"cl6-1",
 "east" : __DIR__"jushi",
]));
set("objects",([
__DIR__"npc/yahuan" : 1,
]));
         setup();
         replace_program(ROOM);
}

