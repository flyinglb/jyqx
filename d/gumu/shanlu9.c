// shanlu9.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�
���ĹŰ�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ����
����ɽ��ع�㣬���������֦ͷ�����䳪�����������������������
���ľ�ʯ��������һƬ������ɽ�֡�
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "northup"    : __DIR__"shulin9",
                "southdown"  : __DIR__"riyueyan",
        ]));

        setup();
        replace_program(ROOM);
}
