// shandao2.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��һ·��ɽ�����Ƽ��գ�������������ȣ���ɽ����֮����
խС������һ�����񣬱ؽ���ɥ�ڴˡ�
LONG    );
        set("outdoors", "heimuya");
        set("exits", ([
            "eastdown" : __DIR__"shandao1",
            "westup"   : __DIR__"shijie1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
