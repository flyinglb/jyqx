// /u/beyond/mr/cl6-5.c
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
��������ȥ����æ���Լ������顣�����ǳ��ȵ����죬�����Ǿ�����
long);
         set("exits", ([
             "west" : __DIR__"cl6-4",
             "east" : __DIR__"cl5-6",
             "north" : __DIR__"jingyinge",
]));
         setup();
         replace_program(ROOM);
}

