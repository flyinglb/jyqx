// jiulou1.c

inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
��Ҿ�¥���书��Բ�����ڵ�Ψһһ�ң����������ֶ�û
�С�¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ���
�ƾ͸�·ȥ�ˡ�¥����������
LONG
        );
        set("exits", ([
                "south" : __DIR__"beijie",
                "up" : __DIR__"jiulou2",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

