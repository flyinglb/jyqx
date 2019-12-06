// Room: /city/ximen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ���������
������ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����ʾ(gaoshi)��
    �������ﷸ��������ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס������
�ʡ�һ����ֱ����ʯ���������������졣�����ǽ��⣬����ġ����εġ�
��·�ģ����˴Ҵҡ������ǳ��������һƬ���֡�
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east"  : __DIR__"xidajie2",
		"west"  : __DIR__"ximenroad",
		"north" : "/d/taohuacun/taohua1",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
                "/d/mingjiao/npc/fenggongying" : 1,
        ]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}

