//nongshe.c
inherit ROOM;

void create()
{
        set("short", "ũ��");
        set("long",
             "������һ��Сũ�ᣬ�Ҿߺ��¡��������˱Ƚϸ�ԣ��\n"
        );
        set("exits", ([
                "west" : __DIR__"guangchang",
        ]));
        set("objects",([
		__DIR__"npc/woman" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
