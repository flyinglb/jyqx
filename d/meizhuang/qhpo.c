// qhpo.c
inherit ROOM;

void create()
{
        set("short", "�滱��");
        set("long", @LONG
��������滱���ˣ��������Ŵ��СС��ǧ��ٹֵĻ������е�
����һֱ���죬�е����������ƣ������������ԼԼ����һ�������
�����������ޣ��������֡�
LONG
        );
        set("outdoors", "meizhuang");
        set("exits", ([ /* sizeof() == 2 */
            "eastup" : __DIR__"xiaodao",
            "north"  : __DIR__"senlin1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

