// Room: /d/mingjiao/gudi4.c

inherit ROOM;

void create()
{
	set("short", "�����ɾ�");
	set("long", @LONG
�ſ��Ų���ǰ������ֱ�����������ţ�����һ���߷���·����
������������������ܸ�ɽ���ƣ��ƺ�ب��������δ���˼�������
����ѩ����ƣ��վ��������޷���Ԯ���롣
LONG );
	set("outdoors", "mingjiao");
	set("exits", ([
		"north" : __DIR__"gudi3",
	]));
	set("objects", ([
		__DIR__"npc/monkey" : 2,
		__DIR__"npc/bigmonkey" : random(2),
	]));
	setup();
	replace_program(ROOM);
}
