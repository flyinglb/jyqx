// by mayue

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
������һƬ�����֣�����Ŀ�������ͷ�����ܶ��ǲ���Ĺ��ɣ���
��඼Ī������Ŀ����ˣ�ֻʣ��һЩ�Ұ׵����ɴ������������͸
����������֦��϶���䵽���У�ů����ġ�������һ��ž����㲻��һ
����š�
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
                "east" : __DIR__"sl8",
                "northwest" : __DIR__"sl4",
                "west" : __DIR__"sl6",
                "northeast" : __DIR__"sl5",
                "north" : __DIR__"caodi",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

