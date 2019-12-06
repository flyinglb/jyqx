inherit ROOM;
#include <ansi.h>
#define POEM_DOC	"/doc/poem/doc"
#define POEM_DIR	"/doc/poem/"

string look_shelf();

void create()
{	
	set("short", "������");
	set("long", @LONG	
����һ�����ĵ�С���ᡣһ����Ⱦ�����(shelf) �Ϸ���������
��������������������ʫ�ʡ��������read����ȡ��һλ���ɰ����
Ů������ͷ���飬���ýŲ���̧ͷ���㡣
LONG	);	
	set("valid_startroom",1);
	set("no_steal", "1");
	set("exits", ([	
		"south" : __DIR__"xiaoyuan",
		"north" : __DIR__"xukong",
	]));
	set("item_desc", ([
		"shelf" : (: look_shelf :),
	]));
	setup();
}

void init()
{
	add_action("do_read", "read");
}

string look_shelf()
{
	this_player()->start_more(read_file(POEM_DOC));
	return "\n";
}

int do_read(string arg)
{
	if (arg == "" || file_size(POEM_DIR + arg) <= 0)
		return notify_fail("����û���Ȿ�顣\n");
	log_file("POEM", sprintf("%s read %s.\n", this_player()->query("name"), arg));
	this_player()->start_more(read_file(POEM_DIR + arg));
	return 1;
}
