// by mayue

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����Ӵ�ɵķ��ӣ���Ȼ��ª��ȴ��������ʰ�ĸɸɾ�
����һ�������ڽ���ò���ŵ���ʿ�����ڰ����п�����������
�Ų�������̧��ͷ����
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"northwest" : __DIR__"road3",
//		"south" : __DIR__"zhushe",
//		"west" : __DIR__"wumiao",
		"north" : __DIR__"caoping",
	]));
        set("objects", ([
                __DIR__"npc/zhuge": 1,
	]));

	setup();
	replace_program(ROOM);
}

