//      hubian4.c ����С·
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����С·");
        set("long",@LONG
����ʥ���ߵ�С·��·�೤��û��, ���̿�ϲ��
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "north" : __DIR__"shanjiao",
                "south" : __DIR__"hubian3",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
