// Room: /guiyun/shanlu2.c
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
		"southwest" : __DIR__"shanlu1",
		"southeast" : "/d/suzhou/road1",
	]));
	set("objects", ([
		__DIR__"npc/qiuqianzhang" : 1,
	]));
	setup();
	replace_program(ROOM);
}
