
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
               "east" : __DIR__"wuchang",
        ]));

        set("objects", ([
              "/d/shaolin/npc/mu-ren" : 4+random(2)
        ]));

        set("outdoors", "emei" );

        setup();
        replace_program(ROOM);
}
