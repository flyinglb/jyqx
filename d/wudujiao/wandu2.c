// by mayue

inherit ROOM;
string* npcs = ({
	__DIR__"npc/wandu1",
	__DIR__"npc/wandu2",
	__DIR__"npc/wandu3",
	__DIR__"npc/wandu4",
	__DIR__"npc/wandu5",
});

void create()
{
	set("short", "�򶾿�");
	set("long", @LONG
������һ����Ȼ�γɵ�ʯ�������������󡣶������������
����ʯ����ʱ���������δ��ˮ�������ڶ��У�����������ʪ����
�Ժ�Ȼ����һ�����С��������������ƺ����и�Сһ���֧����
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
              "south" : __DIR__"wandu3",
//		"westdown" : __DIR__"wdsl3",
		"north" : __DIR__"wandu1",
	]));
        set("objects", ([
	        npcs[random(sizeof(npcs))] : 1,
	]));
    

	setup();
	replace_program(ROOM);
}

