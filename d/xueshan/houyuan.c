//      houyuan.c ��Ժ
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","��Ժ");
        set("long",@LONG
������ѩɽ�µĺ�Ժ����Ժ�������˼������ѩ�ɣ�
�ڰ׻λε�ѩɽ�����£�����ƮȻ�������Ķ����ϱ�����
�䳡�������Ǻ��š�
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "eastdown" : __DIR__"dilao",
                "north" : __DIR__"houmen",
                "south" : __DIR__"chang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

