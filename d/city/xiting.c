// Room: /city/xiting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ŵ�����������֪�����鷿���鰸�����ҵط��ż������ƵĹż���
�������ע�����ǽ�Ϲ���һ���ܴ�ĵ�ͼ(ditu)��
LONG );
	set("item_desc", ([
		"ditu" : "����һ�������������н��ĵ�ͼ�������и�����ɫ��ȦȦ��㣬�Լ����˾���\n"
		"���������ҿ�����Ϊ��ϸ���ƺ���Ѱ��һ���ر�ĵص㡣\n",	
	]));
	set("exits", ([
		"east" : __DIR__"ymzhengting",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

