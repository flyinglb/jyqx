inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
����һƬ���֡�������ȥ�����������в��°����߰���һ��ʯ������
Щ���Ǵ���Թ��Ǿ��������ģ�����Ϊ�������������ӣ�����Ϊ�˻�Ըƽ
�ġ��������������һ��������
LONG );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"ta1",
		"west" : __DIR__"ta3",
		"east" : __DIR__"ta2",
                "north" : __DIR__"damen",
        ]));
	set("objects",([
                __DIR__"npc/saodiseng" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
