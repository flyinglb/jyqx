// Room: /d/quanzhou/chating.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG
����һ��·�ߵ�С��ͤ����ɽ·���˳��ڴ˴�ЪЪ�š�ͤ����
�м������Ӻͼ�֧���ʡ���Χ��һƬ���֡�
LONG );
        set("exits", ([
                "west" : __DIR__"qzroad4",
        ]));
        set("objects", ([
            "/d/heimuya/npc/xiang" : 1,
        ]));
        set("outdoors", "quanzhou");
//	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

