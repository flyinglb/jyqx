// mubanlu.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "ľ��·");
	set("long", @LONG
����һ����ľ���̳ɵ�С������Ȼ���Ǻܳ�������ȴ���ó��̵�ʮ��ϸ
�ģ���һЩϸ΢�����Ҳע�⵽�ˡ���·���Ժ�����һЩ�滨������ʹ��·
�����Ŀ������ĸо���
LONG );
	set("exits", ([
		"south" : __DIR__"muwu3",
		"north" : __DIR__"xiaodao4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xiaoyao");
	setup();
	replace_program(ROOM);
}
