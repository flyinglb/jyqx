// wuchang.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����Ƕ����ɵ����䳡������������
�����������ɵ������ڴ�ϰ��������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
               "north" : __DIR__"wuchang",
        ]));

        set("objects", ([
              "/d/shaolin/npc/mu-ren" : 1+random(4)
        ]));

        set("outdoors", "emei" );

        setup();
        replace_program(ROOM);
}
