// shulin2.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
������һ���ּ��С���ϣ����ܶ�������Զ���ƺ���һ�ǽ�����
���ܴ�������¶�˳�����Ҳ������ɽ����һ������֮�ࡣ��Щ����
�󶼽в��������������䶼�Ѿ��ܳ��ˡ�
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "southwest" : __DIR__"shulin3",
                "northeast" : __DIR__"shulin1",
        ]));

        setup();
        replace_program(ROOM);
}

