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
                "east"  : __DIR__"liangong7",
                "west" : __DIR__"liangong8",
		"north" : __DIR__"xwdian",
		"south" : __DIR__"xuanwu",
        ]));
        setup();
}