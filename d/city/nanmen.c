// Room: /city/nanmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�����ϳ��ţ���ǽ�������˹���ƣ������˻������̸��и�ҵ�Ĺ�棬
�ٸ��ĸ�ʾ(gaoshi)��˲�̫��Ŀ���ٱ��Ǳ������Ļ���Ц������������
�����Ǻ�������ִ�ڡ�һ����ֱ����ʯ�������ϱ��������졣
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"south" : "/d/wudang/wdroad1",
		"north" : __DIR__"nandajie2",
		"west"  : __DIR__"jiaowai8",
		"east"  : __DIR__"jiaowai7",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
		"/d/city2/npc/shisong" :1,
        ]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}

