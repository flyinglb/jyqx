// by mayue

inherit ROOM;
string* npcs = ({
	__DIR__"npc/qiandu1",
	__DIR__"npc/qiandu2",
	__DIR__"npc/qiandu3",
	__DIR__"npc/qiandu4",
	__DIR__"npc/qiandu5",

});

void create()
{
	set("short", "ǧ����");
	set("long", @LONG
������һ����Ȼ�γɵ�ʯ�������������󡣶������������
����ʯ����ʱ���������δ��ˮ�������ڶ��У�����������ʪ����
�Ժ�Ȼ����һ�����С���������
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
              "south" : __DIR__"qiandu1",
//		"westdown" : __DIR__"wdsl3",
//		"north" : __DIR__"baidu1",
	]));
        set("objects", ([
	        npcs[random(sizeof(npcs))] : 1,
	        npcs[random(sizeof(npcs))] : 1,
	]));
    

	setup();
	replace_program(ROOM);
}

