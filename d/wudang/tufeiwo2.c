// tufeiwo2.c ����С·
// by Cleansword 1996/2/2

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һ��Ƨ��������С·�ϣ���������ɭɭ�����֡�ֻ������ǰ�󣬵���
��������ǵص������֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ
��������գ��������ڵ�˿��Ҳ�ޡ���˵���ﾭ�������˳�û�����ɾ�����
LONG );
        set("outdoors", "wudang");
	set("no_sleep_room",1);
	set("exits", ([
		"east" : __DIR__"tufeiwo3",
		"north" : __DIR__"tufeiwo1",
	]));

        set("objects", ([
                __DIR__"npc/tufei1" : 3,
		__DIR__"npc/baibian" : 1,
        ]));
//        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

