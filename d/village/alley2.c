// Room: /d/village/alley2.c

inherit ROOM;

void create()
{
        set("short", "С�ﾡͷ");
        set("long", @LONG
������С��ľ�ͷ��һֻ��ľ���ϰ��ż������ƵĶľߣ�����������
Щ����ͷ����������һ�ɼ��㡢����ͺ���������һ���ζ������������
�Ǵ��ڵ�Ʀ����å�ۼ��ĵط���
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "southeast" : __DIR__"alley1",
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xxx");
        set("objects", ([
            __DIR__"npc/punk": 1,
            __DIR__"npc/dipi": 1,
        ]) );

        setup();
        replace_program(ROOM);
}

