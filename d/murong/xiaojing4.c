// /u/beyond/mr/xiaojing4.c
//this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",GRN"С��"NOR);
set ("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�ǰ�����С���ˣ�һλ��������Ůվ����ǰ���㱻������ò��
����������������������������������ϻ�����������ò����Ů��
long);
         set("outdoors","mr");
/*       set("objects",([
             __DIR__"npc/abi" : 1,
]));
*/       set("exits",([
             "east" : __DIR__"xiaoting",
             "southwest" : __DIR__"xiaojing3",
]));
         setup();
         replace_program(ROOM);
}

