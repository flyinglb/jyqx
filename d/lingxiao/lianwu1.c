//LUCAS 2000-6-18
// lianwu1.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������ǵ����䳡�����Ϸ��ż���ľ�ˣ��ǹ���������
����֮�á��������������ֳֳ������������������ڳ���������
����
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "east"      : __DIR__"fudian1",
        ]));
        set("objects", ([ 
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "lingxiao" );
        setup();
        replace_program(ROOM);
}

