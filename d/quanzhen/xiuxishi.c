// xiuxishi.c ��Ϣ��
// By Lgg,1998.9

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�ܴ�ķ��䣬���߷ǳ��谵������û��ʲô��Ķ�����
ֻ���м����һ����ʰ����������Ĵ󴲣����ϵı���Ҳ�����
������࣬���ž�������˯����
LONG
        );

        set("exits", ([
                "west" : __DIR__"wuchang2",
                "northwest" : __DIR__"wuchang1",
                "south" : __DIR__"shantang",
        ]));
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("no_beg",1);
        set("no_fight",1);
        set("no_steal",1);

        setup();
        replace_program(ROOM);
}

