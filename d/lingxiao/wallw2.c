// wallw2.c

inherit ROOM;

void create()
{
        set("short", "��ͷ");
        set("long", @LONG 
�ߴ���ʤ������ֻ��ѩ����˪Ҳ�׷׶��¡�ͷ�����ϻ���ʯ
��ľ�⣬һ���Ӿ�˪ѩ���죬�����ס���ʫ�ơ�����˪ѩ����
���������Ҳ���������˼�ɡ�
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "west" : __DIR__"wallw3",
                "east" : __DIR__"wallw1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 1,
        ])); 
        setup(); 
        replace_program(ROOM);
}

