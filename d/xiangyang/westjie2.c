// Room: /d/xiangyang/westjie2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����Ǻܴ��ʮ�ֽֿڣ����������ڴ�֣�������һ����
¥��¥ǰ�߸ߵĹ���һ�����ң�����������д�š�����ݡ���
����������������ͨ������㳡������ɴ�׻��š�
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"westjie1",
		"west"  : __DIR__"westjie3",
		"south" : __DIR__"juyiyuan",
		"north" : __DIR__"westroad1",
	]));
	set("objects", ([
		__DIR__"npc/wusantong" : 1,
	]));
	setup();
	replace_program(ROOM);
}

