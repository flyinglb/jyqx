// Room: /d/xiangyang/walls7.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ϳ�ͷ");
	set("long", @LONG
�������������ϳ�ͷ��һЩ�α����ڳ�ͷѲ�ߣ�һ������
�������������ܸ����سǲ��ϣ�һЩ���������鹭�������
�ų��µĶ�����
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"northwest" : __DIR__"wallw8",
		"eastdown"  : __DIR__"walls5",
	]));
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}
