inherit ROOM;

void create()
{
	set("short", "�ذ��Ŷ����");
	set("long", @LONG
����һ����������Ĵ��������ͨ���ذ��š�����ͨ����������
LONG );
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"di_an1",
		"west" : __DIR__"di_anmen",
	]));
	set("objects", ([
		__DIR__"npc/flowerg" :  2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


