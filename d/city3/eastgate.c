// Room: eastgate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
���ǳɶ������ţ��������Ϸ����š����š�����������֣���ǽ
�����ż��Źٸ���ʾ(gaoshi)��һ����ֱ����ʯ��������������
�졣�����ǽ��⣬һƬƽƽչչ��ƽԭ��⣬���ǲ����츮֮������
�ơ������ǳ��
LONG
	);
        set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"fuheqiaoe",
		"west"  : __DIR__"eastroad2",
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
