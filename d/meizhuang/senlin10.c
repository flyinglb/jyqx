// senlin2.c
inherit ROOM;

void create()
{
        set("short", "��ľ԰");
        set("long", @LONG
������÷ׯ�İ�ľ԰����һ�ߵ���������ߵ���һ�������޾�
��Сɭ��һ��������������������������������кܶ�в�������
�ֵ�������ľ�����������У�ֻ�����Ƭ���־��������һ�飬����
��ȥ�źá�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "south" : __DIR__"senlin9",
            "north" : __DIR__"senlin7",
            "west" : __DIR__"senlin3",
            "east" : __DIR__"senlin6",
        ]));
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/jiading.c" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "meizhuang");

        setup();
        replace_program(ROOM);
}

