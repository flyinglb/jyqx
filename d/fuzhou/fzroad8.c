// Room: /d/fuzhou/fzroad8.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ӹ��ŷŽ����£�������ɽ�д䣬���㷺����С�۴�����
̲֮�У����ϻ���ˮ�죬����ƽ������������ʮ��ˮ·������Ϧ
����
LONG );
	set("exits", ([
		"northwest" : __DIR__"yanping",
		"southeast" : __DIR__"fzroad9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

