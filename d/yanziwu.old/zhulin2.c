//ROOM: /d/yanziwu/zhulin2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
��βɭɭ������ϸϸ���͸������ݺύ���ڱ����ա������˼���
����΢��������֣�����ɳɳ֮���������в����㷲�������������һ
����ʯ���̳ɵ���С����ǰ���졣
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "west" : __DIR__"zhulin1",
            "east" : __DIR__"zhulin1",
            "north": __DIR__"zhulin3",
            "south": __DIR__"zhulin2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
