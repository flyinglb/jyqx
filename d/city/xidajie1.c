// Room: /city/xidajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����
ϡ�٣������ĵغ������塣������һ�����ֵĹ㳡���ϱ��Ǳ�Ӫ�����߾�����
���ˡ�
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"guangchang",
		"south" : __DIR__"bingyindamen",
		"west"  : __DIR__"xidajie2",
		"north" : __DIR__"yamen",
	]));

	setup();
	replace_program(ROOM);
}

