inherit ROOM;

void create()
{
	set("short", "������ͬ");
	set("long", @LONG
����������ϣ��е��ƺ���Щ����ϱ����ǿյ�����С��,����
���������ˡ�������һ����ݡ������������������һ�����紵������
����ס���˸������� 
LONG );
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"mianguan",
		"south" : __DIR__"alley2",
		"north" : __DIR__"xichang2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

