// sroad2.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
һ��ɽ·������ɽ�䡣������ȥ�����Լ�����ѩɽ����ɫ��ѩ
�����������ԡ�
LONG );
        set("exits",([
                "eastdown"  : __DIR__"sroad1",
                "westup"    : __DIR__"sroad3",
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

