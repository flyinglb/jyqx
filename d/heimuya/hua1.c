//ROOM: hua1.c

inherit ROOM;

void create()
{
	set("short", "��԰");
        set("long", @LONG
����һ�������µ�С��԰��԰�У���÷�������ɴ�أ���
�õ��ľ߽��ģ�����ȥ��һƬ��ݵء�
LONG    );
        set("exits", ([
            "west" : __DIR__"grass2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
