// Room: westgate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
���������������⣬ֻ���ߴ�ĳ�ǽ��ʵ���أ�������ϸ���̲�
�Ź������ˣ�һ�ж��Եþ�����������ǽ�����ż��Ÿ�ʾ(gaoshi)��
����ԶԶ���Կ����������Ϫ��ˮ�������ǳ��
LONG );
        set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west"  : __DIR__"nanheqiaow",
		"east"  : __DIR__"westroad2",
                "south"  : __DIR__"yizhan",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�ɶ��ᶽ\n�����\n";
}
