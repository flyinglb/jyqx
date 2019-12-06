// Room: /city2/guancaidian.c

inherit ROOM;

void create()
{
	set("short", "�ײĵ�");
	set("long", @LONG
����һ�ҹײĵ꣬һ���ţ�һ���ľζ�˱Ƕ��������������
�����������Ӷ����ƾɡ�������һ�����ң�һ����ʮ��ͷ�ľ�׳��
�ӵ����ſڡ�
LONG );
	set("item_desc", ([
		"guancai" : "������۹ײģ�ÿ����ʮ���ƽ�\n",
	]));
	set("objects", ([
		"/d/city2/npc/gaoyanch" : 1,
	]));
	set("exits", ([
		"northwest" : __DIR__"alley2",
		"east"      : __DIR__"guancai2",
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("money_paid") && dir == "up" )
	{
        if(objectp(present("gaoyanca", environment(me))))
        return notify_fail("���峬һ�µ���¥��ǰ��ŭ�����Ƚ�Ǯ��\n");
        }
	if ( me->query_temp("money_paid") && dir == "west" )
	return notify_fail("���峬�ܵ��ű���ס���͹��Ѿ����˽��ӣ����᲻��¥�������أ�\n");
	return ::valid_leave(me, dir);
}
