// Room: /xiakedao/shidong7.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ��ʯ���������ǹ⻬��ʯ�ڣ����ڸɸɾ�����һ����Ⱦ
ȴ����һ�ˣ�������Χ�е����ѣ���ʯ����ҫ�����Ƿ���
LONG );
        set("exits", ([
                "west" : __DIR__"shidong8",
                "north" : __DIR__"shidong6",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
