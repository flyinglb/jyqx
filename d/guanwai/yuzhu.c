// /guanwai/yuzhu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ʒ����ϣ��з����ͦ�㣬���ͻ��������������´к��һˮ����
�����ߣ�ע����أ����ǹż����صġ�����Ȫ���ˡ�
LONG );
	set("exits", ([
		"north"      : __DIR__"tiyun",
		"northeast"  : __DIR__"baiyun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
