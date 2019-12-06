// Room: /t/wanjiegu/xiaoting.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����һ��С�������ϵ���һ�Ծ��򡣶����ķ������������÷
����գ������ϵ��ķ��Ǵ����ﶬ������ȫ�Ҵ��˷�λ����������
�����˲��������黭��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"grassland",
            "north" : __DIR__"hall",
        ]));
        set("objects", ([
            __DIR__"npc/gan" : 1,
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
