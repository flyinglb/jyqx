// Room: /city/biaojuhy.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����ھֺ�Ժ");
	set("long", @LONG
�ھֺ�Ժ��ƽ����ʦ�Ǵ�ȭ����֮�������˼���ľ׮ʯ
���⣬�������
LONG );
	set("exits", ([
		"south" : __DIR__"biaojuzt",
	]));
	set("objects", ([
		__DIR__"npc/zheng" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

