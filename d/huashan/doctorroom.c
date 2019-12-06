// Room: /d/huashan/doctorroom.c

inherit ROOM;

void create()
{
        set("short", "���м�");
        set("long", @LONG
���������ס��һλ���У��ų���ҽ����˵��������ʲô������֢,ֻҪ����
����������ֵ�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"road1",
        ]));
        set("objects", ([
            __DIR__"npc/doctor" : 1,
        ]) );
        set("no_clean_up", 0);
        set("no_fight",1);
        set("no_magic",1);
        set("outdoors", "huashan");

        setup();
        replace_program(ROOM);
}
