//LUCAS 2000-6-18
inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿���Ŵ����գ����߻谵������������
ֻ�����߷��ż�����ʰ����������Ĵ󴲣����ž�������˯����
LONG );
        set("sleep_room", "1");
        set("no_clean_up", 0); 
        set("no_fight", 1);
        set("exits", ([
                "east" : __DIR__"zoulang1",
        ]));
        setup();
        replace_program(ROOM);
}

