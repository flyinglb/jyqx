// Room: /d/hengshan/cuipinggu1.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ڹ��г�ˢ�����������ʹ���ɽ����Ͽ�����࣬����ǧ
�����絶���������������ƣ������Թž�������ͨ���ڵص��ʺ�
Ҫ��������һ�򵱹����Ī��֮�ơ�
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu2",
		"northwest"  : __DIR__"jinlongxia",
	]));
	set("objects", ([
		__DIR__"npc/wen" : 1,
	]));
	set("outdoors", "hengshan");
//        set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}

