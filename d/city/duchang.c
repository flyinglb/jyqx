// Room: /city/duchang.c
// YZC 1995/12/04 
//modified by wind
inherit ROOM;
void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ����������Ƕġ���С��
�ķ��䣬¥�°�¥�Ƕġ����ӡ��ķ��䣬��¥�ǹ���,  �ϱ�����һ���Ʊ��.
LONG
	);
	set("exits", ([
		"up" : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
		"west" : __DIR__"duchang3",
       		"north" : __DIR__"lotfz",
                "south" : __DIR__"lotcd",
       ]));
	setup();
}
int valid_leave(object me, string dir)
{
   if ((dir != "east"&&dir != "south"&&dir != "north") && this_player()->query("age")<18)
                return notify_fail("Сë���������Ϲ�պ�ʲô?!\n");
        return ::valid_leave(me, dir);
}
