// /u/beyond/mr/xiaojing8.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"С��"NOR);
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ������������������濴ȥ��һ
Ƭ�����֣������Ǻ�Ժ��������һ��С����
long);
         set("outdoors","mr");
         set("exits",([
             "north" : __DIR__"xiaojing6",
             "south" : __DIR__"houyuan",
]));
	setup();
	replace_program(ROOM);
}

