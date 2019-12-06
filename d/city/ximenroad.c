// Room: /city/ximenroad.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
    set("short", "���Ŵ��");
	set("long", @LONG
������������������������ͨ�����ǣ��򶫾��������ˡ��ϱߣ��¿���
�������᳡��ÿ������֮�ڣ��������У��㲻����ȥ��ʶһ�µ���ĳ�����
�
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"ximen",
  		"west"  : "/d/city4/road1",
		"south" : __DIR__"wudao4",
	]));
        set("objects", ([
            "/d/village/npc/boy" : 3,
        ]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "south") me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}

