// xiaoting.c С��
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
������һ��СС�����ã�Ҳ����Ϊ������ǰ���������õġ�����
�������Χ�Ĺ�������һЩ���㷢������ȼ����һЩ�͵ơ������
�������������ª��һ��һ�ζ���ʰ�ľ���������
LONG
        );

        set("exits", ([
                "south" : __DIR__"zhengting",
                "north" : __DIR__"qianting",
                "west" : __DIR__"xiaowu1",
                "east" : __DIR__"xiaowu2",
        ]));

        setup();
        replace_program(ROOM);
}
