// muwu2.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "Сľ��");
        set("long", @LONG
����һ�䲻�Ǻܴ��ľͷ���ӣ����￴�������ҩ�ң����аڷ��Ÿ���
��ͬ����ҩ���þߺ�һЩ�Ѿ�����˵�ҩ��
LONG );
	set("exits", ([
		"south" : __DIR__"xiaodao3",
	]));
	set("objects", ([
		__DIR__"npc/xuemuh" : 1,
//		__DIR__"npc/yaotong": 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
