//ROOM: /d/yanziwu/zuijing.c

inherit ROOM;

void create()
{
        set("short", "׺��¥");
        set("long",@LONG
�������Ŵ���̺�����в��õ���ⱦ���������鱦������ڷŵ�
������Ŀ���㿴����Ϊ�Ķ�������˳�����߼�����������Щ���ҡ�����
����һ�ܺ�ľ¥�ݡ�
LONG );
        set("exits", ([
            "west" : __DIR__"canheju",
            "east" : __DIR__"jiashan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
