//ROM

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������һ��ɽ�ȣ�������ֲ�Ų�ƺ�������ǡ�������̡���
�����á�������һ����ɽ��ʯ����
LONG    );
        set("outdoors", "heimuya");
        set("exits", ([
            "east" : __DIR__"linjxd1",
            "southup" : __DIR__"dating3",
            "west" : __DIR__"shidao1",
        ]));
        set("objects",([
            __DIR__"npc/kid" : 2,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
