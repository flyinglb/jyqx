inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С����Ͼ�����ɲ�����������ˡ�
LONG );
        set("outdoors", "tianlongsi");
	set("exits", ([
		"south" : __DIR__"damen",
		"east" : __DIR__"dadao3",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

