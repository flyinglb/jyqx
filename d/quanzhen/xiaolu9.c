// xiaolu9.c ��ɽС·
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
                "east" : __DIR__"xiaolu10",
                "west" : __DIR__"xiaolu5",
                "north" : __FILE__,
                "south" : __FILE__,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

