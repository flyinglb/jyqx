// /u/beyond/mr/cl3.c
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
��������ȥ����æ���Լ������飬������һ�㵡���������������ǳ��ȵ����죬
�����Ǻ�Ժ��������һ���᷿�� 
long);
         set("exits", ([
             "north" : __DIR__"cl2",
             "east" : __DIR__"houyuan",
             "south" : __DIR__"xiangfang1",
             "west" : __DIR__"cl3-1",
]));
         setup();
         replace_program(ROOM);
}

