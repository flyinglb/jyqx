// mtroad1.c  ����

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
            "east"  : "/d/henshan/hsroad5",
            "west"  : __DIR__"mtroad",
            "north" : __FILE__,
            "south" : __DIR__"mtroad2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

