//      kedian.c �͵�
//      Designed by secret (����)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","�͵�");
        set("long",@LONG
������һ��·�ߵ�С�͵ꡣ���������˶�����������
��Ϣ��������·���Ե�����ԭ��
LONG );
//        set("valid_startroom",1);
        set("exits",([
                "east" : __DIR__"tulu2",
        ]));
        set("objects", ([
            __DIR__"npc/xiaoer2" :1
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

