// Room: /d/shaolin/rukou.c
// Date: YZC 96/02/06

inherit ROOM;

void create()
{
	set("short", "���ж����");
	set("long", @LONG
���������ж�����ڡ�����ڳ����ģ���ʯ����ɵ�ǽ����
��Ƕ�˼��Ŷ쵰��С�����ӣ��ų����ɵĻƹ⡣����������Ҳֻ
�����䵽����Զ�ĵط�������ʪ�����ģ��ű߲�ʱ���ߵ����ѵ�
�ݹǣ������Ĵ����������ڻ��죬ʹ����ĵ���ð��һ������
�ĺ��⡣������·���أ���ã�ѱ档�㲻֪����������������
LONG );
	set("exits", ([
		"south" : __DIR__"wuxing"+random(5),
		"north" : __DIR__"andao1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

