// Room: /guiyun/nvxiangfang.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "Ů�᷿");
	set("long", @LONG
�����ǹ���ׯŮ���ӵ���Ϣ�ң����ż���ľ�������Զ���һ֧�߽�
���ӣ�����������ݽ�һ�ż��ʣ�����һ��������ɢ�ŵ������㡣
LONG );
        set("sleep_room",1);
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"huating",
	]));
	setup();
	replace_program(ROOM);
}

