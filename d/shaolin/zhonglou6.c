// Room: /d/shaolin/zhonglou6.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
�ش�������һ����������ɽ�磬������ˡ������ɼ����ֵ�
��ͷ������ɽ�Ķ��崦����һƬСС��ƽ�أ�����ֲ�����þ��ɣ�
���ƺ���ʲô�������������⡣ͷ���ϵ�¥�忪�˸��󶴣�����
һ�ڴ��ӡ�������ֻ�ܿ������ӵ��±�Ե������ڶ����ģ�ʲô
Ҳ��������
LONG );
	set("exits", ([
		"up" : __DIR__"zhonglou7",
		"down" : __DIR__"zhonglou5",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

