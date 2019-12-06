// houyuan.c ������Ժ

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
�����ǲ�����Ժ�����ֹ���������Ŀ��������ͭ�����ߵ��������ʡ�����
Ӧ�о��У�ֻҪӵ��һ�����͹����һ�����ˡ���Ա��������������ϣ���
���ĵغ��Ų�����������һ����(men)��
LONG );
	set("item_desc", ([
		"men" : "�������ƺ�ͨ��һ�����ҡ�\n",
	]));
	set("exits", ([
//		"east" : __DIR__"dongxiang",
		"south" : __DIR__"dayuan",
		"west" : __DIR__"xixiang",
	]));
	set("objects", ([
		__DIR__"npc/cui" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_unlock", "unlock");
	if (present("cui yuanwai", environment(this_player())))
		delete("exits/east");
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/east"))
		return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("laofang key", this_player())))
		return notify_fail("�㲻��������\n");
	set("exits/east", __DIR__"dongxiang");
	message_vision("$N��һ��Կ�״������ţ�����Կ��ȴ���ˡ�\n", this_player());
	destruct(ob);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("cui yuanwai", environment(me))) && 
                     dir == "west" && living(present("cui yuanwai", environment(me))))
		return notify_fail("��Ա�⵲ס���㡣\n");
	return ::valid_leave(me, dir);
}
