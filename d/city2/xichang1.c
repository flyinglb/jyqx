

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣������ȥ�������Ľֵ�
������ͷ�����߾����찲�š�һ����Ȳ�����ʱ�ӱ��ߵ�ϷԺ�������ϱ߾�
�Ǿ����������ġ��ش��á�ҩ�ꡣ
LONG );
        set("outdoors", "city2");
	set("exits", ([
		"east" : "/d/city2/tian_anm",
		"south" : "/d/city2/huichunt",
		"west" : "/d/city2/xichang2",
		"north" : "/d/city2/xiyuan",
	]));
	set("objects", ([
		"/d/city2/npc/flowerg": 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	me->delete_temp("warned");
	me->delete_temp("hastryup");
	return ::valid_leave(me, dir);
}
