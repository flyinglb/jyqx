// tufeiwo3.c С·��ͷ
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
		"west" : __DIR__"tufeiwo2",
	]));
        set("objects", ([
                __DIR__"npc/tufei1" : 2 ,
                __DIR__"npc/tufeitou" : 1, 
        ]));
//        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

