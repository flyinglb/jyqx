// caoping.c
inherit ROOM;
void create()
{
        set("short","��ƺ");
        set("long",
             "������һ�鷼��ƺ���̲����𣬺������裬���˸е���⡣\n"
         "����ż��Ҳ�������˻��ߡ�\n"
        );
        set("exits", ([
                "west" : __DIR__"shijie",
        ]));
        set("objects" , ([
             __DIR__"npc/caihuashe" : random(2),
        ]));
        set("outdoors", "baituo");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
