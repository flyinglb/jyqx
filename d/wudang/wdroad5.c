//Room: wdroad5.c
//Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ�������Ũ�ܵ����֣���ɭɭ
��ʮ�����ˡ������������¶��߽��ˡ�����ȴ��һƬ�ݵء�
LONG);
        set("outdoors", "wudang");
        set("exits", ([
            "northwest" : __DIR__"wdroad6",
            "north"     : "/d/xiangyang/caodi6",
            "east"      : __DIR__"wdroad4",
        ]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

