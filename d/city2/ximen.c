// Room: /city2/ximen.c

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ���������
������ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����ʾ(gaoshi)��
�ﷸ�����������ӳ����ǣ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס�������ʡ�һ����
ֱ����ʯ���������������졣�����ǽ��⣬����ġ����εġ���·�ģ���
�˴Ҵҡ������ǳ��
LONG );
        set("outdoors", "city2");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : __DIR__"xichang2",
		"west" : __DIR__"ximenwai",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	setup();
}

string look_gaoshi()
{
	return "������ػ�һ�ڷ���! \n�ٱ�һ�ˣ��ͽ�ʮ��;\n"
          "׽��һ�ˣ��ͽ������\n֪�鲻���ߣ���ն!\n���ݷ�\n";
}

