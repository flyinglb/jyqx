// Room: /city2/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š����š��������֣���ǽ������
���Źٸ���ʾ(gaoshi)��һ����ֱ����ʯ���������������졣
�����ǽ��⣬Խ�����ſ��Կ�����������������������������
ͨ������������ǳ����š�
LONG );
        set("outdoors", "city2");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/city2/road1",
		"northwest" : __DIR__"chaoyan2",
		"west" : __DIR__"dongcha2",
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

