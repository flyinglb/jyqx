//      hubian3.c ����С·
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����С·");
        set("long",@LONG
����ʥ���ߵ�С·���������ģ��װ׵��ƶ��ں���Ư
�ƣ��������١�����������һЩ��������Ĳ�֪���İ�����
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "north" : __DIR__"hubian4",
                "southwest" : __DIR__"hubian2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
