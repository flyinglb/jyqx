//ROOM: /d/yanziwu/muti.c

inherit ROOM;

void create()
{
        set("short", "ľ��");
        set("long",@LONG
����һ������֦�ܳɵ�ľ�ݣ�������ͨ��ˮ�档�������Ա���֦��
һֻС�� "ɯɯ��ɯ��ɯɯ��ɯ" �Ľ�����������������һ����
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "eastup" : __DIR__"qinyun",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
