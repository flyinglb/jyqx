inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ����ʯ·��һ·�����������������ˡ����ϱ��Ƕ��š�
�������������ߡ�
LONG );
        set("outdoors", "city2");
	set("exits", ([
		"northwest" : __DIR__"chaoyang",
		"southeast" : __DIR__"dongmen",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


