//ROOM: shufang.c

inherit ROOM;

void create()
{
    set("short", "�߷���");
    set("long",@LONG
���ǡ����չ������鷿����ǽ�ڷ���һ����ܣ���������������Ÿ�
���鼮������������һ��īɫС�������ϵ���¯ð���������̣���ǰ�и�
���ſɹ�����������������֮���������㲻�ɵͺ�������һ���ž���
�ڣ���
LONG );
    set("exits", ([
        "west" : __DIR__"men2",
    ]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
