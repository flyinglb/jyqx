// Room: /d/shaolin/bagua7.c
// Date: YZC 96/01/19

inherit ROOM;

#include "/d/shaolin/bagua.h"

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǳ��ǰ������ı�ȫ�ɴֲڵ�Ƭ���ݶ���ɡ���ʯ
������ȱ�ڼ��Ϸ촦Ȯ���������Ĺ��ޣ�������������
���ɡ����Ͽ���һ��С׭��������ͨ��أ���������񡱡�
���ܻҳ�����������ܲ��������Ѿ������С������ƺ�����
����ʬ�壬���Ѹ��û��ң��Ų���������ʬ�����ϵ�����Ҳ
���Ʈɢ��
LONG );
	set("exits", ([
		"Ǭ" : __DIR__"bagua7",
		"��" : __DIR__"bagua6",
		"��" : __DIR__"bagua5",
		"��" : __DIR__"bagua4",
		"��" : __DIR__"bagua3",
		"��" : __DIR__"bagua2",
		"��" : __DIR__"bagua1",
		"��" : __DIR__"bagua0",
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (check_dirs(me, dir))
		return notify_fail("��ȶ��˻��أ�����ɮ�ࡣ\n");
	return ::valid_leave(me, dir);
}

