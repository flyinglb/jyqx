// by mayue


inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�����ű��µĻ��������ܹ��ű�ɴ����ʣ��ݽ���¯��Ʈ��һ
���������������һ���ۺ���ȹ����Ů�����ڴ��߷����������Ų��������
����һ������ü΢΢һ򭣬�ƺ���̫���ˡ�
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"huating",
		"south" : __DIR__"huating2",
		"west" : __DIR__"huayuan1",
		"north" : __DIR__"huating3",
	]));
        set("objects", ([
                __DIR__"npc/hetieshou": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

