// Room: /d/xiangyang/juyiyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��������������ʹ���չ��������ص���˼�����������ø�
��ǰ��Ч������ʿ�ĵط���������һ��������ͨ�ȣ���������
�����䳡��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"juyilianwu1",
		"west"  : __DIR__"juyilianwu2",
		"south" : __DIR__"juyilang",
		"north" : __DIR__"westjie2",
	]));
	set("objects", ([
		__DIR__"npc/zhuziliu" : 1,
	]));
	setup();
	replace_program(ROOM);
}

