// Room: /lingzhou/chema.c
// Java Sep. 23 1998

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
һ�ҵ͵��ĳ����ջ�������൱�¾ɣ��ܲ����ۣ��������ڼ�Ǯ��
���������ڱ��ŵĽ�ͨҪ���ϣ����̾�����ѡ��������ţ�����Ҳ�൱
������Ҳ������������������صķ������顣
    ǽ�Ϲ���һ������(paizi)��
LONG );
	set("no_fight", 1);
        set("no_sleep_room",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹʮ��������\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"majiu",
		"west" : __DIR__"nandajie",
		"up"   : __DIR__"chema2",
	]));
	setup();
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
