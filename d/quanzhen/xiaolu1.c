// xiaolu1.c ��ɽС·
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "��ɽС·");
        set("long", @LONG
�����Ǻ�ɽ�ϵ�С·������С·�������˹������޳����ģ�
Ҳ��ֻ����ǰ�Ĳ�ҩ�˲ȶ��ˣ��ֳ�����һ��С·����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northeast" : __DIR__"xiaolu2",
                "southwest" : __DIR__"houshan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

