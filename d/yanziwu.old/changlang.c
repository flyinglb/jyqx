//ROOM: /d/yanziwu/changlang.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
ֻ���������ߣ�һ�ɸ������󣬲�ʱ�м�ֻ�������ɵĴ��ȼ��ɹ���
���ȵľ�ͷ��һ����԰���������ƺ�����һ�㣬���̲�ס������ȥ��
����
LONG );
        set("exits", ([
            "east"  : __DIR__"huizhen",
            "west"  : __DIR__"lixiang",
            "north" : __DIR__"shijian",
            "south" : __DIR__"huayuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
