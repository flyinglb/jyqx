// Room: /d/fuzhou/shiqiao.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ǳ���һ������ͨͨ��ʯ�š�������м�������ʷ
�ˣ��Ų�������̦��������С��Ϸˮ������ϴ�µ�ĸ�״�
���ǳ����Լ��ĺ��ӡ�
LONG );

	set("exits", ([
                "west"  : __DIR__"xiangyang",
                "east"  : __DIR__"nanmendou",
	]));
	set("objects", ([
                "/d/songshan/npc/sha" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}


