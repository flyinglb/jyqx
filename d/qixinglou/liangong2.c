// liangong.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
	set("long", @LONG
����������¥���ӵ����䳡���������ż���ľ�ˣ��Ա��гԶ�����˯���ĵط���
LONG );
        set("exits", ([ /* sizeof() == 2 */
        "south"     : __DIR__"restroom2",
        "east"      : __DIR__"water2",
        "west" : __DIR__"fulouzhu",
        ]));
     set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//   set("no_clean_up", 0);
     set("outdoors", "city" );

     setup();
}
 
