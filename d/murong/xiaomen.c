// /u/beyond/mr/xiaomen.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"С��"NOR);
         set("long", @long
������һ��Բ��С�ţ�С�ŵ�������һ�����ȣ���������������������
�е��˶���æ���Լ������顣
long);
         set("exits", ([
             "north" : __DIR__"cl5-3",
             "south" : __DIR__"cl5-4",
]));
         setup();
         replace_program(ROOM);
}

