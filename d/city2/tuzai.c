
inherit ROOM;

void create()
{
	set("short", "���׳�");
	set("long", @LONG
���������׳��������������������ζ��ż��һ���ȷ紵����
��ʱһ�ɳ���Ϯ����ֱѬ������Ż��һ������������������ָ��
�Ż����ɱ��ȥë������Ǿ����������׳�����˵�������е�
���ⶼ�Ǵ�������ȥ�ġ�
LONG );
	set("exits", ([
		"east" : __DIR__"nandaj2",
	]));
	set("objects", ([
		"/d/city2/npc/lilishi":1,
		"/d/city2/npc/huoji1":2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
