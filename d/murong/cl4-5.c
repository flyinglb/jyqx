// /u/beyond/mr/cl4-5.c
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
��������ȥ����æ���Լ������飬�������ӻ��ң������ǳ��ȵ����졣
long);
         set("exits", ([
 "west" : __DIR__"zahuoshi",
             "north" : __DIR__"cl4-4",
]));
set("objects",([
__DIR__"npc/xiaotong" : 1,
]));
         setup();
         replace_program(ROOM);
}

