// xiaodao3.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ�����ϵ������ּ�С������;�羰��֮���ģ�����������εض�
�����԰ٻ����ޡ���������������
LONG );
	set("exits", ([
		"south" : __DIR__"qingcaop",
		"north" : __DIR__"muwu2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xiaoyao");
	setup();
	replace_program(ROOM);
}
