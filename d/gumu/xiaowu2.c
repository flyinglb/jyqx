// xiaowu2.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������С��Ůι��ѵ�����ķ��ݣ��ݽ��Ϲ��źܶ�������ε�
�䳲����δ���ţ����ŵõ�һ����۵����㡣
LONG
        );

        set("exits", ([
                "west" : __DIR__"xiaoting",
                "east" : __DIR__"xiaowu3",
        ]));

        set("objects", ([
                __DIR__"obj/fengjiang" : 3,
                __DIR__"obj/fengmi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
