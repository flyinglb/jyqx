// /guanwai/tiyun.c

inherit ROOM;

void create()
{
	set("short", "���Ʒ�");
	set("long", @LONG
�����山����һɽ�壬�弹���ݺ��ٲ���Զ�����ڰ����ƣ��������ݣ�
�������Ʒ塣
LONG );
	set("exits", ([
		"south"      : __DIR__"yuzhu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
