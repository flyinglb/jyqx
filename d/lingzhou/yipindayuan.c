// Room: /lingzhou/yipindayuan.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "һƷ�ô�Ժ");
	set("long", @LONG
����������һƷ�õĴ�Ժ����ʯ�̾͵�ʯ��·���Ӵ���ֱͨ������
��������Ρ���һƷ�ô�������������һ����ˣ�����һ�治֪��ɫ��
����ͦ�����Ʈ���ţ��˺��Ǹ��Ͱ�һЩ�Ļ������á�����һ��ƽ����
������Ҳ�����ʷ�����Ժ���м����������ż�Ƭ����������һЩ��ʿ
����ȭ��
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"north"  : __DIR__"yipindating",
		"south"  : __DIR__"yipingate",
		"east"   : __DIR__"yipinjieyin",
		"west"   : __DIR__"yipinzhang",
	]));
	set("objects", ([
		__DIR__"npc/yun" : 1,
		__DIR__"npc/yipinwushi" : 2,
	]));
	setup();
	create_door("south" , "ͭƤ����", "north" , DOOR_CLOSED);
	"/clone/board/yipin_b"->foo();
}

