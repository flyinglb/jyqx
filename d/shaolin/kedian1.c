// Room: /shaolin/kedian.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
����һ��Զ��������������ջ������ǳ���¡������οͶ�ѡ��
��������ţ��������������������صķ������顣��С����������
æ������ת���Ӵ�����ǻ�����Ŀ��ˡ�ǽ�Ϲ���һ������(paizi)��
LONG );
	set("valid_startroom", 1);
	set("no_fight", 1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));
	set("objects", ([
		__DIR__"npc/xiao-er" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nanyang",
		"up" : __DIR__"kedian2",
	]));
//	set("no_clean_up", 0);
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
