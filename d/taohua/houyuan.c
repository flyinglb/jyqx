// /d/taohua/houyuan.c
#include <room.h>;
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����ɽׯ�ĺ�Ժ��Ժ�а��ż��������ˣ��Ǹ��һ������������õġ�
Ժ�����һ�����Ψһһ��ɽ�壺��ָ�塣�����һ�ɽׯ��ɽ������������
�ɡ�
LONG );
	set("outdoors", "taohua");
	set("exits", ([
	    "north" :__DIR__"dating",
	    "west" :__DIR__"xiaowu",
	    "east" :__DIR__"siguoshi" ,
	]));
	set("objects", ([
	      __DIR__"npc/jiguan" : 5,
	]) );
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
