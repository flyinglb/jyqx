// shanlu12.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�
���ĹŰ�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ����
����ɽ��ع�㣬��������һ����·������������һ�����ѵ�ɽ·��
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "northup"   : __DIR__"shanlu11",
                "southdown" : __DIR__"shanlu13",
        ]));

        setup();
        replace_program(ROOM);
}
