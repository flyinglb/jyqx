// by mayue

inherit ROOM;

void create()
{
	set("short", "�嶾ɽ·");
	set("long", @LONG
�������嶾ɽ�е�ɽ��С·�����������������ϡ�ɽ·�ϼž�
������������һ˿���޵ĺۼ�����˳�ֲ�������·�е�֦������֦
��Ȼһ�������˻�ȥ������...����Ȼ��һ�����ƿ�֦�Ķ��ߡ� 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"eastup" : __DIR__"wdsl2",
		"southup" : __DIR__"wdsl3",
		"west" : __DIR__"taohua",
//		"northwest" : __DIR__"xiao3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

