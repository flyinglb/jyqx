//      houmen.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
����ѩɽ�µĺ��š�һƬ���������ģ������������
��Ҳ�㣬����Ҳ�����Ǻ��ţ���Ȼδ�⺮�ᣬ��Ҳ�ܿ�
��Ҵ�š�
LONG );
        set("exits",([
            "south" : __DIR__"houyuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

