// huajing.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�������е�С�����컨������������裬���ս�����Ҳ�����ɳ������������
Сɽ���������µ�С¥��
LONG
	);
        set("exits", ([ 
		"north" : __DIR__"liangong4",
		"south" : __DIR__"yaoyue", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",0);
	setup();
	replace_program(ROOM);
}
