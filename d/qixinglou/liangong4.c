// liangong.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
	set("long", @LONG
����������¥���ӵ����䳡���������ż���ľ�ˣ��Ա��гԶ�����˯���ĵط���
LONG );
        set("exits", ([ /* sizeof() == 2 */
     "east"     : __DIR__"restroom4",
     "south"    : __DIR__"water4",
     "north"    : __DIR__"zhanglao2",
        ]));
     set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//   set("no_clean_up", 0);
     set("outdoors", "city" );

     setup();
}
 
