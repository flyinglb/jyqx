// liangong.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
	set("long", @LONG
���������¸��û�������������õĵط����Ա�����һ�������ܣ���������������С�
LONG );
        set("exits", ([ /* sizeof() == 2 */
     "south"     : __DIR__"tangzhu",
     "east"      : __DIR__"restroom9",
     "north"     : __DIR__"water9",
        ]));
     set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//   set("no_clean_up", 0);
     set("outdoors", "city" );

     setup();
}
 
