// senlin8.c
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
            "south" : __DIR__"qhpo",
            "north" : __DIR__"senlin7",
            "west" : __DIR__"senlin5",
            "east" : __DIR__"senlin2",
        ]));
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/jiading.c" : 1,
        ]));
        set("outdoors", "meizhuang");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

