// Room: /d/quanzhou/nanmen.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "Ȫ������");
	set("long", @LONG
�������Ϸ���һ��Ȫ�ݵ����š���������һƬ��Ұ��
LONG );
	set("exits", ([
		"south" : __DIR__"bamboo",
                "north" : __DIR__"zhongxin",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

