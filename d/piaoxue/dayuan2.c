inherit ROOM;
void create()
{
        set("short", "�׻�����Ժ");
        set("long", @LONG
�����ǰ׻��õ���Ժ������ǰ���ǰ׻��õ���������
������������ڵ��������ĵط���
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"baihu",
                "west" : __DIR__"bhdian",
		"north" : __DIR__"liangong3",
		"south" : __DIR__"liangong4",
        ]));
        setup();
}