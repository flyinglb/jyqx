//      guangchang.c �㳡
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","�㳡");
        set("long",@LONG
������ѩɽ���ڵĹ㳡���㳡ʯ���̾�, ��������, ƽ������ʵ��
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"xiaoyuan",
                "west" : __DIR__"chang",
                "north" : __DIR__"dadian",
                "south" : __DIR__"shanmen",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


