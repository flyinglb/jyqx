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
            "north" : __DIR__"senlin3",
            "west" : __DIR__"senlin2",
            "south" : __DIR__"senlin3",
            "east" : __DIR__"senlin2",
        ]));
        set("outdoors", "meizhuang");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

