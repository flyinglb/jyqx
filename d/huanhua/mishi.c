// mishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ��տյ����ӣ�ֻ��һ����һ�ʣ�һ�����ѣ��ǳ��򵥡�
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"shufang", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
