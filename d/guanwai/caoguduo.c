// /guanwai/caoguduo.c

inherit ROOM;

void create()
{
	set("short", "�Ȳݶ�");
	set("long", @LONG
����һ�����İ��棬�����ǰ������һƬ�Ͱ������ꡣԶԶ��ȥ����
�պ�ѳɵĹȲݶ⣬�������飬�������ж��ٸ���������Ƭ���������У�
�Ϳɽ��볤�״�ɽ�ˡ�����������һ�ƴ��̣������ƺ����ˡ�
LONG );
	set("exits", ([
		"northwest" : __DIR__"mantianxing",
		"east"      : __DIR__"baihe",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
