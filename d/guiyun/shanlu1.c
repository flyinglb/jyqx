// Room: /guiyun/shanlu1.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һƬũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ�������һЩ���ڸ�����ũ�ˡ�
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"shulin4",
		"south"     : __DIR__"taihu",
		"northeast" : __DIR__"shanlu2",
	]));
	set("objects", ([
		"/d/village/npc/poorman" : 1,
	]));
	setup();
	replace_program(ROOM);
}
