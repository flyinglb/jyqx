
inherit ROOM;


void create()
{
	set("short", "������Ժ");
	set("long", @LONG
�����ǿ�����Ժ��������һ��С��԰��������һ�������ߵ�ֱͨ��
���á�������һ������ϱ߾��ǿ������ȥ��˽�����䳡��
LONG
);
	set("exits", ([
		"west" : __DIR__"huayuan",
		"east" : __DIR__"mapeng",
		"north" : __DIR__"neitang",
		"south" : __DIR__"kang2",
	]));
	set("objects", ([
		"/d/city2/npc/guanjia" : 1,
		"/d/city/npc/jiading" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

