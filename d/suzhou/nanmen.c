// Room: /d/suzhou/nanmen.c
// Date: May 31, 98  Java

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
�������ݸ����ϳ��š�������������ٯ�������������
������ſڵĹٱ����ں��Ҳ������������������������һ
�ݸ�ʾ(gaoshi)���ϱ�һ����ֱ�Ĺٵ���
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"north" : __DIR__"nandajie2",
		"south" : __DIR__"road5",
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

