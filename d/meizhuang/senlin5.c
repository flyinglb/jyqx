// senlin5.c
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
        set("exits", ([ /* sizeof() == 8 */
            "southeast" : __DIR__"senlin4",
            "northeast" : __DIR__"senlin2",
            "west" : __DIR__"senlin2",
            "east" : __DIR__"senlin2",
            "north" : __DIR__"senlin3",
            "south" : __DIR__"senlin5",
            "northwest" : __DIR__"senlin4",
            "southwest" : __DIR__"senlin6",
        ]));
        set("outdoors", "meizhuang");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

