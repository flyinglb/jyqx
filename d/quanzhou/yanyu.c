// Room: /d/quanzhou/yanyu.c
// Date: May 23, 96   Jay

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����¥�����Ϻ����ĵ�һ��С���ϡ��Ϻ����겻�ϵ�ˮ������
���ֵ��������ɵġ�¥���Ǽҷ��ꡣ
��������װ��¥�ݡ�������¥��
LONG );
	set("exits", ([
                "up"    : __DIR__"yanyu2",
                "north" : __DIR__ "nanhu1",
	]));
        set("objects", ([
            __DIR__"npc/xiaoer" : 1
        ]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

