//ROOM: /d/yanziwu/chuantang.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
��֪��ʲô�ܹ��ɽ�������������ã��������ۣ���������������
�Ͼ��Ǻ�Ժ�ˣ�������һ�������á�
LONG );
        set("exits", ([
            "south" : __DIR__"lixiang",
            "north" : __DIR__"cuixia",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
