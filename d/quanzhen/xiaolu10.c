// xiaolu10.c ��ɽС·
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "��ɽС·");
        set("long", @LONG
�����Ǻ�ɽ�ϵ�С·������С·�������˹������޳����ģ�
Ҳ��ֻ����ǰ�Ĳ�ҩ�˲ȶ��ˣ��ֳ�����һ��С·�����ߵ����
�������·�ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"xiaolu11",
                "west" : __DIR__"xiaolu9",
                "north" : __FILE__,
                "south" : __DIR__"xiaolu12",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

