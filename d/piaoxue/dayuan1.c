inherit ROOM;
void create()
{
        set("short", "��������Ժ");
        set("long", @LONG
�����������õ���Ժ������ǰ���������õ���������
������������ڵ��������ĵط���
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"qldian",
                "west" : __DIR__"qinglong",
		"north" : __DIR__"liangong1",
		"south" : __DIR__"liangong2",
        ]));
        setup();
}