// Room: /d/village/shouse.c

inherit ROOM;

void create()
{
        set("short", "С����");
	set("long", @LONG
����һ����������ɵķ��ݣ�����ֻ�м������ƵļҾ㡣�ڿ��ſڵ�
ǽ����һֻ�տյ����ӣ��������������������Ѽ֮��ļ��ݡ�
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"sroad2",
        ]));
//        set("no_clean_up", 0);
        set("objects", ([
            __DIR__"npc/oldwoman": 1
        ]) );

        setup();
        replace_program(ROOM);
}
 
