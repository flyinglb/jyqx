// shanlu3.c ɽ·
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ǰ�������һ����ɽ�ȣ��ߵ������ľ����Щ��ȫ���ǰ�����
������һ��������ɽ·��������ɽ�䣬Ҫ��ҹ�ﻹ�濴��������
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southwest" : __DIR__"shanlu2",
                "northup" : __DIR__"cuipinggu",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
