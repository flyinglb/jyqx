// by wind

inherit ROOM;

void create()
{
	set("short", "�й�������Ʊ�ڵ�");
	set("long", @LONG
������һ���С�ķ��䣬¥�ϵķ����ﴫ����ߺ������ĶĲ�����
����һ����Ҳû��, һ̨����������������. ������û��ÿ�ܿ���
��ʱ��.Ҫ��Ҫ��һע��(help caipiao)?
LONG
	);

	set("exits", ([
		"north" : __DIR__"duchang",
	]));

	set("objects", ([
		__DIR__"obj/lottery" : 1,
	]));

	setup();
}

