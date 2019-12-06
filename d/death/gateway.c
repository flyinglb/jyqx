// Room: /d/death/gateway.c

inherit ROOM;

void create()
{
	set("short", "ۺ������");
	set("long", @LONG
����������һ����ɫ��¥֮ǰ����¥�Ͽ����������֣�ۺ���ǡ���
�ϲ�Զ����һ���ţ����Ϲ�Ӱ����������ȴ��������������������߽�
��¥ֻ��һƬ������ģ�ֻ��������ɫ�Ļ���������ֵ���˸����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : "/d/death/road1",
		"south" : "/d/death/gate",
	]));
	set("objects", ([
		__DIR__"npc/bgargoyle": 1
	]) );

//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south") {
		return notify_fail("һ���ն������������������....\n"+
			       "û�л�ͷ·��!\n");
	}
	else return 1;
}


