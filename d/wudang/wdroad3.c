// wdroad3.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ�
LONG );
        set("outdoors", "wudang");
	set("exits", ([
		"south" : __DIR__"wdroad4",
		"north" : __DIR__"wdroad2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
 
