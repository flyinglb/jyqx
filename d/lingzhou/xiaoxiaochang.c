// Room: /lingzhou/xiaoxiaochang.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "СУ��");
	set("long", @LONG
����������Ӫ��СУ����ƽʱ��ʿ�Ǿ���������������Ϻ�ƽ����
������ָ��̨���и��������ɵ���ˣ��˶�һ������һ������������
Ӫ��ɫ����ӭ���������졣ƽʱ��ʿ��һ�����������ϳ��٣������
����������Ұս����������ʳ����Ѳ�ߡ�
LONG );
	set("exits", ([
		"north" : __DIR__"biaoqiyin",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" :3,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

