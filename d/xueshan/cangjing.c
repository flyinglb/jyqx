//      cangjingge.c �ؾ���
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","�ؾ���");
        set("long",@LONG
������ѩɽ�µĲؾ�֮����������������ܶ�������
�伮����һ����Ҳ��������
LONG );
        set("exits",([
                "northwest" : __DIR__"dating",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/lingzhi" : 1,
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

