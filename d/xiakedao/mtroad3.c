// mtroad3.c  ����

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ï�ܵ�ɭ�֡����ܶ���������ĳ��ݣ�һ����ɭ�ֲ���
���ա�Զ����ʱ����Ұ�޵ĺ��У���ʵ�ڲ��������������
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
            "east"  : __DIR__"mtroad2",
            "west"  : __FILE__,
            "north" : __FILE__,
            "south" : __DIR__"mtroad4",
        ]));
        set("objects", ([
            __DIR__"npc/qiaofu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

