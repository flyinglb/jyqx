// liangong3.c

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
�߽��������ʱ�е�����һ�ᣬ���崺�磬�����ǽ�Ϲ���һ�����ܵġ��仨
ʫ��ͼ�������µ��ţ��⾳��Զ��������һ�Ŵ����������ࡣ
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"huayuan1", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
