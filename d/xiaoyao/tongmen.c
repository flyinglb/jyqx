// tongmen.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "ͭ��");
	set("long", @LONG
����һ�����ε�ͭ�ţ����Եı������š��Ż����ء��ĸ����֡�
LONG );
	set("exits", ([
		"south" : __DIR__"shiji3",
		"west" : __DIR__"fangjian3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
