// Room: /city2/yongdingmen.c


inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ţ��������Ϸ����š������š��������֣���ǽ������
���Źٸ���ʾ (gaoshi)��ÿ�춼������˴������ǳ��뾩�ǣ��������
�ٱ��̲�ø�����ϸ�� һ����ֱ�Ĵ�����ϱ��������졣�ϱߵ������
���������������������ͨ�������ġ�
LONG );
        set("outdoors", "city2");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south" : "/d/city2/road5",
		"north" : __DIR__"nandaj2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

string look_gaoshi()
{
	return "������ػ�һ�ڷ���! \n�ٱ�һ�ˣ��ͽ�ʮ��;\n"
          "׽��һ�ˣ��ͽ������\n֪�鲻���ߣ���ն!\n���ݷ�\n";
}

