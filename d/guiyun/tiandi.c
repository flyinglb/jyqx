// Room: /guiyun/tiandi.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һƬũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ����д�����ų�һ�������֣�������һЩ���ڸ���
��ũ�ˣ���·��̰��·Ҳ���Դ���侮�ַָ��С��������
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);
	set("exits", ([
		"northeast"  : __DIR__"shulin5",
		"west"       : __DIR__"yixing",
	]));
	set("objects", ([
		__DIR__"npc/banjiu" : 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	me = this_player();
	if (dir == "west" )
	{
		me->receive_damage("qi", 10);
		tell_object(me,"���������ͻ���С���⣬���ĺ�����խ�����������˽�ȥ��\n");
	}
	else
	{
		me->receive_damage("qi", 10);
		message_vision("$N��������С���⣬������ǰ��ȥ��\n", me);
	}
	return 1;
}

