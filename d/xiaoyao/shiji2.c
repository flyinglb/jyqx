// shiji2.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ�γ�����ʯ������������ȱ�������������е�������ĸо���ʯ
�����Ŷ���������չ��һ����ȥ��������������ͷ��
LONG );
	set("exits", ([
		"east" : __DIR__"shishi2",
		"west" : __DIR__"shidong",
		"north" : __DIR__"fangjian2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
