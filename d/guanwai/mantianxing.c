// /guanwai/mantianxing.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ������ƽԭ����������û���κ�Сɽ���꣬����һ����Ҳ��
������̧����ȥ����ƽ�߱�ֱ�Ľ�������ѩԭ�ָ������ߡ���˵ҹ��������
�����ڵ����ɱ�������Ƕ�����ɽ�����Ƕ��ڴ������ϲԵı��ӡ�
LONG );
	set("exits", ([
		"southeast" : __DIR__"caoguduo",
		"west"      : __DIR__"ermenkan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
