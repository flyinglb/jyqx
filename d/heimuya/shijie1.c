// shijie1.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ɽ·ͻȻ���ͣ�����ɽ��������м�����һ��խխ��ʯ�ף�
�������˲�����С�
LONG    );
        set("outdoors", "heimuya");
        set("exits", ([
            "eastdown" : __DIR__"shandao2",
            "westup"   : __DIR__"shijie2",
        ]));
        set("objects", ([
            __DIR__"npc/fansong" : 1, 
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
