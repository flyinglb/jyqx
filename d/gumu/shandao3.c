// shandao3.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˶�ɽ·��ͨ����ɽ�š���������һ��Ƭ���֡������¿�������
һ���ϴ�ĺ���
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "southup"   : __DIR__"shulin12",
                "northdown" : __DIR__"taiyi1",
        ]));

        setup();
        replace_program(ROOM);
}
