// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ʯ�����������Լ���Կ��������ǵĳ�ǽ��������
��Сɽ��
LONG );
        set("exits", ([
            "east" : __DIR__"xxroad1",
            "northup" : __DIR__"xxroad3",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}

