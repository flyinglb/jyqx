// Room: /d/hengshan/xuankong1.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "�����±�¥");
	set("long", @LONG
�����������µı���¥��Ҳ�Ǳ���ͤ����¥���ӣ�������Ԩ��
�ȵ���������ڼ䵤�����������ջ��ͨ����¥��
LONG
	);
	set("exits", ([
		"south"    : __DIR__"zhanqiao",
		"up"       : __DIR__"sanjiaodian",
		"westdown" : __DIR__"cuiping2",
	]));
	set("objects", ([
		__DIR__"npc/yafu" : 1,
	]));
//        set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}

