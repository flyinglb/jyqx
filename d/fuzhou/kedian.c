// Room: /d/fuzhou/kedian.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
ɽҰ�͵�ʮ�ּ�ª��һ��С����̨������һƬ���������ڵ�
�ϣ��Ե��൱æ�ҡ���̨�����Ÿ�����(paizi)��
LONG );
	set("exits", ([
		"east" : __DIR__"erbapu",
	]));
	set("item_desc", ([
		"paizi" : "������ֻ��Ӧ�Ժȣ������ޡ�\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

