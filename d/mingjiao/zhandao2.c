//zhandao2.c
inherit ROOM;

void create()
{
        set("short", "ջ��");
        set("long", @LONG
������ͨ�����̵�ջ��������ï�����ƣ�������ա�
    ԶԶ������ͷ��������������������ۼ�ķ��ܻ����ˡ�
LONG);
        set("exits", ([
                "northup"   : __DIR__"tianweitang",
                "southdown" : __DIR__"zhandao1",
        ]));
        set("outdoors", "mingjiao");
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
