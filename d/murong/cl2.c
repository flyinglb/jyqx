// /u/beyond/mr/cl2.c
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
��������ȥ����æ���Լ������飬������һ�㵡����������һ��С����������
���ȵ����졣
long);
         set("exits", ([
             "north" : __DIR__"xiaojing5",
             "west" : __DIR__"cl1",
             "south" : __DIR__"cl3",
]));
         setup();
         replace_program(ROOM);
}

