// Room: /guiyun/nanxiangfang.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
�����ǹ���ׯ�е��ӵ���Ϣ�ң����ż���ľ�������Զ���һ֧
�߽ż��ӣ��������������һ��С���������ǻ�԰��
LONG );
        set("sleep_room",1);
	set("no_clean_up", 0);

	set("exits", ([
		"west" : __DIR__"huating",
	]));
	setup();
	replace_program(ROOM);
}

