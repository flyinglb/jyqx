// Room: /d/xiakedao/xkroad5.c
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "���ɹ����");
	set("long", @LONG
С�岻��ȴ�и��ô��ɹ����������С���ڳ������ǵ���ˣ��
�������֡����Ϻ����ϣ��и��������󺣣���Ȼ������
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"north"   : __DIR__"xkroad6",
		"west"    : __DIR__"xkroad4",
	]));
	set("objects", ([
		__DIR__"npc/boy": 1,
		__DIR__"npc/girl": 1,
		__DIR__"npc/yufu": 1,
	]));
	setup();
	replace_program(ROOM);
}

