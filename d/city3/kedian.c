// Room: /chengdu/kedian.c
// Date: Feb.14.1998 by Java
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ȫ�������Ŀ͵꣬����ǳ���¡������οͶ�ѡ����
����ţ��������������������صķ������顣��С����������æ��
����ת�����صĴ�ζ�ٻ�����ʵ������˳�������ǳɶ������ٰ�Ŀ�
ջ���Ӵ��Ÿ����봨�Ĺٲ����ˡ�ǽ�Ϲ���һ������(paizi)��
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ��ʮ��������\n",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
	    "northwest" : __DIR__"southroad1",
	    "up"        : __DIR__"kedian2",
	]));
	setup();
	"/clone/board/kedian3_b"->foo();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
