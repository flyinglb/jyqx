//LUCAS 2000-6-18
// Room: wuqi.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������ǵĵ����̡��߽�����������壬���������
��Ҫ�䡣��ϸһ����ǽ�Ϲ����˴��СС������ɫɫ�ĵ�����һ
��������������ȫ����Ʒ��������ԯ���������˽�����������
�ڵ�ӭ��ǰ����
LONG );
        set("exits", ([
                "east" : __DIR__"iceroad2",
        ]));
        set("objects", ([
                __DIR__"npc/xuanyuan": 1,
        ]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        setup();
        set("no_clean_up", 0);
        replace_program(ROOM);
}

