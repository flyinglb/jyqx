// /u/beyond/mr/cl4-2.c
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
��������ȥ����æ���Լ������飬�����ǳ��ȵ����죬�����ǿ������������
��Ժ��
long);
         set("exits", ([
             "west" : __DIR__"houyuan",
             "south" : __DIR__"keting",
             "north" : __DIR__"cl4",
             "east" : __DIR__"cl4-3",
]));
         setup();
         replace_program(ROOM);
}

