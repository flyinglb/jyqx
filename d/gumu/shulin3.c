// shulin3.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
���������ֵı�Ե����������Ѿ���ϡ���ˡ�������һ����ɽ��
��Լ����ɽ�����������У��ƺ���ʲô���ܵĽ�����ɽ�ƻ��ͣ���
ɽ�������де���������ľ��
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "south" : __DIR__"caodi",
                "northeast" : __DIR__"shulin2",
        ]));

        setup();
        replace_program(ROOM);
}
