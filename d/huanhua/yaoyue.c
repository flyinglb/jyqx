// liangong4.c

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
С¥���Ҷ���д�š�����¥���������ǽ�®�����֮�����ϵ�¥������Ŀ������
������ׯһ�����࣬��ƯҶ��Ϫ�ϣ��������ˮ�ߣ����Ϫɴ�����ˣ�����Ϸ�ں�
���ĺ��ӣ��Ǽ�Ȯ�����ڶ��ķ羰���顭��
LONG
	);
        set("exits", ([ 
		"north" : __DIR__"huajing",
					
        ]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",0);
	setup();
	replace_program(ROOM);
}
