//RJQLWCH.C

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�߽������������䳡������������Щ��֡�����Ľ���
�ǲ��������໥�д裬���Ǵ��������ƵĻ��ߣ�ͬһ����ֵ�
װ�ô򶷡�װ�ôӲ��ƿ�ԭ�أ�ֻ�����ƺ��߱��ò���ĸ���
��������������˿�������ڽ������֡�
LONG );
	set("exits", ([
		"north" : __DIR__"rjqyuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren": 5,
	]));                                                    
	set("no_clean_up", 0);
//	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
