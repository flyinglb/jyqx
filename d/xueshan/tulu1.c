//      tulu1.c ��·
//      Designed by secret (����)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","��·");
        set("long",@LONG
����һ�������۵���·������ȴҲ��խ����ɢ�ĸ���
��¶���������̵�Ƶ������������ѩɽ������ԭ�ıؾ�֮
·��
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"caoyuan",
                "west" : __DIR__"tulu2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

