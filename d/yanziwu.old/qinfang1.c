//ROOM: /d/yanziwu/qinfang1.c

inherit ROOM;

void create()
{
        set("short", "�߷���");
        set("long",@LONG
�����ǹ�Ľ�����ҵ�����С�ĵط���������ˮ��΢�����������
���Ƶĺɻ�Ҷ�㣬������Ƣ���߷�����˶�����һ��ī��ɫ������ͨ��
¥�ϵ���Ϣ�ҡ�
LONG );
        set("exits", ([
            "east"  : __DIR__"yimen",
            "up"    : __DIR__"qinfang2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
