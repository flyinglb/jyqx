// yandong.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "�Ҷ�");
	set("long", @LONG
��������û��˿���Ĺ�����ÿǰ��һ������Ҫ����̽����ʵ������ȴ��
�ý���ƽ������������ʯ��·��һ�㣬ֻ����·���ϵ�������б��Խ��Խ�͡�
LONG );
	set("exits", ([
		"north" : __DIR__"damen",
		"out" : __DIR__"hubian",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
