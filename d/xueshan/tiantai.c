//      tiantai.c ��̨
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","��̨");
        set("long",@LONG
������ѩɽ�µĸߴ������߿ɼ���ΰ�Ĵ�ѩɽ���ϱ�
���Ը�������羵��ʥ����
LONG );
        set("exits",([
                "west" : __DIR__"neidian",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

