//Room: house.c
//Date: Feb.12 1998 By Jave

inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
����һ��С���ݣ���������һ��ũ�ҵķ��ӡ�����򵥵ذ���Щ�Ҿߣ�ǽ
�������Щũ�ߡ���������һ�������ź�һ��С���������˳����������ɫ��
�ŵ������㡣
LONG);
        set("exits", ([
            "north"      : __DIR__"wdroad6",
        ]));
        set("objects", ([
            "/d/village/npc/oldwoman" :1,
            "/d/village/npc/kid" :1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


