// Room: /d/suzhou/yamen.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "���ݸ���");
	set("long", @LONG
���϶������������������һ���������������������ϸ
������ǽ������һ�����ң�������顰����������ĸ������
���Ĵ��֡����ྲ�����رܡ������ӷ������ࡣ֪����������
�����������飬ʦү�����ں�
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"xidajie1",
	]));
	set("objects", ([
		__DIR__"npc/feng": 1,
		__DIR__"npc/shiye": 1,
		__DIR__"npc/yayi": 4,
	]));
	setup();
	replace_program(ROOM);
}
