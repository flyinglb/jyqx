// /u/beyond/mr/cl3-1.c
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
��������ȥ����æ���Լ������飬�����ǻ��ʷ��������ǳ��ȵ����졣
long);
         set("exits", ([
             "east" : __DIR__"hffang",
             "north" : __DIR__"cl3-2",
]));
         setup();
         replace_program(ROOM);
}

