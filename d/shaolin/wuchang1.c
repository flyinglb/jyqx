// Room: /d/shaolin/wuchang1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м�
�����Ų���ľ�ˡ�ʮ����ɮ��������ϰ���ա�������һ����ɮ����
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang2",
		"west" : __DIR__"banruo5",
		"east" : __DIR__"wuchang",
		"north" : __DIR__"zoulang6",
	]));
	set("objects",([
                __DIR__"npc/mu-ren" : 5
        ]));
	set("outdoors", "shaolin");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

