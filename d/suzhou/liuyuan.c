// Room: /d/suzhou/liuyuan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
��԰�����ݵ�һ������֮һ�����Խṹ���ֽ��ܡ����û�
����֡�װ�ξ������Ŷ����С����е�һ��԰��֮����
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"nandajie2",
		"west"  : __DIR__"hehuating",
	]));
	set("objects", ([
		__DIR__"npc/lady1" : 1,
	]));
	setup();
	replace_program(ROOM);
}

