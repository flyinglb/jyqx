// shanlu10.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�
���ĹŰ�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ����
����ɽ��ع�㣬���������֦ͷ�����䳪�������������������¡���
������һ��ɽ·��
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "westup"    : __DIR__"shulin9",
                "eastdown"  : __DIR__"jinliange",
        ]));

        setup();
        replace_program(ROOM);
}
