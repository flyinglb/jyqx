// Room: /city/kedian.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
	����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��������ţ���
������������������صķ������顣��С����������æ������ת���Ӵ�����ǻ����
�Ŀ��ˡ�
LONG
    );

	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
                __DIR__"npc/xiaoer":1,
               "/quest/job/machou":1,
	]));

	set("exits", ([
        "east" : __DIR__"lx",
		"up" : __DIR__"kedian2",
	]));

	setup();
	"/clone/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��ô�ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}

