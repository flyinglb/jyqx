// shulin4.c ����
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
                "north"  : __DIR__"kongdi",
                "south"  : __DIR__"shulin0",
                "east"   : __DIR__"shulin6",
                "west"   : __DIR__"shulin5",
        ]));

        setup();
        replace_program(ROOM);
}
