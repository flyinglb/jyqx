// Room: /d/fuzhou/dongmen.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���ݶ���");
	set("long", @LONG
�������Ǹ���ƽԭ�������￴ȥ�����Լ������ܵĴ��֡�
������ʮ��ؾ��ǹ�ɽ�ˡ�
LONG );
	set("exits", ([
                "east" : __DIR__"shulin",
                "west" : __DIR__"dongxiaojie",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

