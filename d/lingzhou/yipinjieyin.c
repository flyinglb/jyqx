// Room: /lingzhou/yipinjieyin.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����������һƷ�õĽ����ã�ÿ����Ը����һƷ�õĽ������֣���
�����˳䵱�����ˣ������ϸ���������á������Ժ󣬲����ʸ��ɺ���
���ܷ�������ΪһƷ��Ч�������������и�רְ�����ĺ��ӣ�ΪһƷ
�ù㿪��·������һƷ���ڽ�����Ҳȷʵ����ȸ��
LONG );
	set("exits", ([
		"west"  : __DIR__"yipindayuan",
	]));
	set("objects", ([
		__DIR__"npc/nuerhai" :1,
	]));
	setup();
	replace_program(ROOM);
}

