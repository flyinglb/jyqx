// /u/beyond/mr/xiaojing1-1.c
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
��׺�����С�������ʯ���ϣ�ž�žવķ�������������������С������
�죬����͵��˰��ߡ�
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"anbian1",
             "north" : __DIR__"xiaojing1-0",
]));
	setup();
	replace_program(ROOM);
}

