// Room: /d/suzhou/ximen.c
// Date: May 31, 98  Java

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǻų����õ����������ţ��������Ϸ����š����š���
��������֣���ǽ�����ż��Źٸ���ʾ(gaoshi)��������ͨ��
��ɽ��һ����ֱ����ʯ���������������죬�����ǳ��
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west" : __DIR__"road2",
		"east" : __DIR__"xidajie2",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n������\n";
}

