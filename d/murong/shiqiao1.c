// /u/beyond/mr/shiqiao1.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"Сʯ��"NOR);
         set("long",@long
����һ��СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����ʯ�ŵĶ�����
һ������ʯ�̳ɵ�С������������٢��ɽׯ��ǰԺ��
long);
set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaojing5",
             "west" : __DIR__"qianyuan",
]));
	setup();
	replace_program(ROOM);
}

