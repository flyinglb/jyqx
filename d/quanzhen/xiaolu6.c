// xiaolu6.c ��ɽС·
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
                "east" : __FILE__,
                "west" : __FILE__,
                "north" : __FILE__,
                "south" : __DIR__"xiaolu5",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

