//      tulu2.c ��·
//      Designed by secret (����)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","��·");
        set("long",@LONG
����һ�������۵���·��ȴ������ѩɽ������ԭ�ı�
��֮·�����ߵ��Ĵ�����ϡ�ɼ�����������ͨ��������
���ѩɽ�¡�
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"tulu1",
                "north" : __DIR__"tulu3",
                "west" : __DIR__"kedian",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

