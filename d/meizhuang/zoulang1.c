// zoulang1.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����������ȣ�������������λׯ���е�������λƽʱ��
Ϣ�������ĵط����������������ң��ұ��ǻ��ң���ׯ��ͺ���̺�
��ׯ�����������������µ�ʱ�򣬱㵽������ȥ�Ӻ�����ī��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "west" : __DIR__"shushi",
            "east" : __DIR__"huashi",
            "north" : __DIR__"zoulang2",
            "south" : __DIR__"neiyuan",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

