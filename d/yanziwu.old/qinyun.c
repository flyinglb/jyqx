//room: qinyun.c

inherit ROOM;

void create()
{
        set("short","����С��");
        set("long",@LONG
����һ��С������ķ��ᣬ��Ϊ���š���Χϡϡ����������С��
�ݣ�������һ����֪��С�����ǰ뵺�ϡ�
LONG );
        set("exits",([
            "westdown" : __DIR__"muti",
            "east"     : __DIR__"xiaoting",
            "south"    : __DIR__"neitang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

