// wuqiku.c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������͵��������⣬���ϰ����˸���������������������ʿ
����ѡ��
LONG );
        set("exits", ([
                "east" : __DIR__"dating",
        ]));
        set("objects", ([
                "/d/village/obj/zhujian" : 2,
                "/d/city/obj/zhubang" : 2,
                "/d/shaolin/obj/changbian" : 1,
                "/d/city/obj/duanjian" : 1,
                "/d/city/obj/gangdao" : 1,
                "/d/city2/obj/fuchen" : 1
        ]));
        setup();
        replace_program(ROOM);
}
