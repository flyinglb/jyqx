//ROOM: /d/huashan/changlang.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
�����ڳ�����ֻ���������ߣ���������������紵����ϸ������
������ɽ�����ɹ�Ȼ�����������������˵ľ��ҡ�
LONG );
        set("exits", ([
            "west"  : __DIR__"jushi",
            "north" : __DIR__"songlin1",
            "south" : __DIR__"garden",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
