// Room: /lingzhou/jiuguan.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƹ�");
	set("long", @LONG
����һ��С�ƹݣ��������������ţ��忪������棬��ģ�Ĵ���
�����������˶ൽ���������Ъ�ţ�����һ�̰�����ɱ��ţ���⣬����
���ڴ�������̾ƣ����㷹�����֮�ʴ��ϼ����������С���Σ���Ǯ
�����ֺ�ʵ�ݣ������ر������������ǳ�������������¥��¥�ݣ�����
����������
LONG );
	set("exits", ([
		"east" : __DIR__"nandajie",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

