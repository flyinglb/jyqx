// /u/beyond/mr/cl6-3.c
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
��������ȥ����æ���Լ������飬������һ��Բ��С�š�
long);
         set("exits", ([
             "east" : __DIR__"cl6-1",
             "south" : __DIR__"xiaomen1",
]));
set("objects",([
__DIR__"npc/jiading" : 2,
]));
         setup();
         replace_program(ROOM);
}

