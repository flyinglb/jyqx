// Room: /d/xingxiu/xxroad6.c

inherit ROOM;

void create()
{
        set("short", "ɽ��ƽ��");
        set("long", @LONG
ɽ��ƽ�أ����������̵�С�ݣ���Χ���˼���������ɽ����һ����
Ȫ���ݵ������ż�������ʬ���������޵����������á�
LONG );

        set("resource/water", 1);
        set("objects", ([
                __DIR__"npc/obj/yangrou.c" : 3,
                __DIR__"npc/dujiangshi" : 5
        ]));
        set("exits", ([
            "south" : __DIR__"xxroad5",
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}
