// shandao1.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ�
��������ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼ
һʧ�㣬��Ҫ����������Ԩ�ˡ���������һ����Ŀյء�������ͨ
����ɽ�ţ�ԶԶ��������һ���ϴ�ĺ���
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "southeast"   : __DIR__"shanlu7",
                "northdown"   : __DIR__"shandao2",
        ]));

        setup();
        replace_program(ROOM);
}
