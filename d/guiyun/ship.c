// Room: /guiyun/ship.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "ս��");
	set("long", @LONG
����һ�Ҵ��洬�����ϵ��˰�����㣬���Ͼ͸�Щû��Ǯ����
�����Ӽ��غ��İ��ա�
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/haojie" : 1,
	]));
	setup();
	replace_program(ROOM);
}
