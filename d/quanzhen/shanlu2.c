// shanlu2.c ɽ·
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
һ��ɽ·����������ͨ��ɽ�ϡ������ɽ�Ϻ�����һƬ�����֣�
����������¶��ͤ�ӵ�һ�ǣ����������ɽ��·��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northeast" : __DIR__"shanlu3",
                "southeast" : __DIR__"shanlu4",
                "westdown" : __DIR__"shanlu1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
