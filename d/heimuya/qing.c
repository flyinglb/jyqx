//ROM dating
inherit ROOM;
void create()
{
        set("short", "�����ô���");
        set("long", @LONG
���ǡ�������̡��µ������ã������õĴ�����һλ���߾�
�У������㱡�
LONG );
        set("exits", ([
            "north" : __DIR__"chlang2",
            "east" : __DIR__"tang",
        ]));
        set("objects",([
            __DIR__"npc/jiabu"   :1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
