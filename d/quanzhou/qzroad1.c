// Room: /d/quanzhou/qzroad1.c
// Date: Maay 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻���
LONG );
	set("exits", ([
		"northwest" : "/d/taishan/yidao1",
                "south" : __DIR__"qzroad2",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

