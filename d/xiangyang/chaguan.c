// Room: /d/xiangyang/chaguan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ��
���Ű�����һ���ſ��������˿��ˣ������̸��ս�֣���ͷ
�Ӷ�Ԫ���ƴ���Ҫ�����ʲô�����²���ʱ��
LONG );
	set("resource/water", 1);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"northjie",
	]));
	setup();
	replace_program(ROOM);
}

