// shanlu8.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ�
��������ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼ
һʧ�㣬��Ҫ����������Ԩ�ˡ�������һ����Ŀյء���������һ
����ҡ�
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "northup"    : __DIR__"daxiaochang",
                "southdown"  : __DIR__"juyan",
        ]));

        setup();
        replace_program(ROOM);
}
