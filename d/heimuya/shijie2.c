// shijie2.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
Խ���ϣ�ɽ��Խ���ͣ��м��ʯ��Խխ������һ�����ߣ���
��������������Լ����һ��ʯ�š�
LONG    );
        set("outdoors", "heimuya");
        set("exits", ([
            "eastdown" : __DIR__"shijie1",
            "westup"   : __DIR__"shimen",
        ]));
        set("objects", ([
            __DIR__"npc/zhaohe" : 1, 
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
