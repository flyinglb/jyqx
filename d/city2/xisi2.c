inherit ROOM;

void create()
{
	set("short", "���ı����");
	set("long", @LONG
���������ı���֡��ϱ�ͨ������������ͨ��ذ���,������һ����Ժ��
LONG );
        set("outdoors", "city2");
//	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"xisi",
		"east" : __DIR__"di_an4",
		"north" : __DIR__"shuyuan",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke": 1,
	]));
	setup();
	replace_program(ROOM);
}


