// by wind

inherit ROOM;

void create()
{
	set("short", "�й�������Ʊ�ڵ�");
	set("long", @LONG
������һ���С�ķ��䣬¥�ϵķ����ﴫ����ߺ������ĶĲ�����
����һ����Ҳû��, һ̨����������������. ������û��ÿ�ܿ���
��ʱ��.Ҫ��Ҫ��һע��(help help caipiao)?
LONG
	);

	set("exits", ([
		"south" : __DIR__"duchang",
	]));
	set("objects", ([
		__DIR__"obj/lottery2" : 1,
	]));

	setup();
}

