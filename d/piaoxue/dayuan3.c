inherit ROOM;
void create()
{
        set("short", "��ȸ����Ժ");
        set("long", @LONG
��������ȸ�õ���Ժ������ǰ������ȸ�õ���������
������������ڵ��������ĵط���
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"liangong5",
                "west" : __DIR__"liangong6",
		"north" : __DIR__"zhuque",
		"south" : __DIR__"zqdian",
        ]));
        setup();
}