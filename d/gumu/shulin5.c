// shulin5.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬
�������������һȺ���ɫ���۷��������Է�����ȥ���������Ĩ�
�߾���ï�ܵ����֡�
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "east"   : __DIR__"shulin0",
                "south"  : __DIR__"shulin4",
                "north"  : __FILE__,
                "west"   : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
