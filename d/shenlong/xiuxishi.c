// Room: xiuxishi.c

inherit ROOM;

void init();

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ������С��������������ֻ���м����һ����ʰ�øɸɾ���
�Ĵ����������������ӵ���Ϣ����.
LONG );
	set("exits", ([
	    "south"  : __DIR__"zoulang",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);

        setup();
	replace_program(ROOM);
}

