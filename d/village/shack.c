// Room: /d/village/ehouse1.c

inherit ROOM;

void create()
{
        set("short", "��լ");
	set("long", @LONG
����һ��ʮ�ּ�ª���ı�©���С���ӣ���������һ�������Ĵ���û
�У�ֻ��һ���Ű���������Щ�ɲݡ������ӵ�����һ����ƶ���ʵ������
�����졣
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" :__DIR__"wexit",
        ]));
//        set("no_clean_up", 0);
        set("objects", ([
            __DIR__"npc/poorman": 1
        ]) );

        setup();
        replace_program(ROOM);
}
 
