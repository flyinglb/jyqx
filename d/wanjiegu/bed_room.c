// Room: /t/wanjiegu/bed_room.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ӹ��������ң����ڴ������ʹ��ڴ���ľ��֮�ϡ�ǽ
�������˸��ֻ������̵Ķ����������и�С�񣬹��Ϸ���һյ����
�ơ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"left_room",
        ]));
        set("objects", ([
            __DIR__"npc/zhongling" : 1,
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
