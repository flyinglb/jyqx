// Room: /d/fuzhou/nandajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�ֵ����࣬��ľ���졣����ʢ�Ŀ��ȣ���ֲ����������
ˬ���������ųǡ��������Ǹ��ã�������һ�����˹ݡ�
LONG );
	set("exits", ([
		"south"   : __DIR__"nanmendou",
		"north"   : __DIR__"dongjiekou",
		"east"    : __DIR__"weizhongwei",
		"west"    : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));
	set("outdoors", "quanzhou");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

