//  jitan.c ��̳

inherit ROOM;

void create()
{
        set("short","ѩɽ��̳");
        set("long",@LONG
������ѩɽ��ѩɽ��̳���м�һ����̨����ʯ���͡�
��Χ������ľ������ͣ��Ա�һ��ʢˮ��­�����Ű���һ
ֻ���塣һЩʹ��Ϳ�������������������ó��ȡ�
LONG );
        set("outdoors","xueshan");
        set("no_fight",1);
        set("exits",([
                "north" : __DIR__"chang",
        ]));
        set("objects",([
                __DIR__"npc/x_lama": 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

