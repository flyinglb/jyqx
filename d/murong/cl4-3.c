// /u/beyond/mr/cl4-3.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ��Ҷ�
��������ȥ����æ���Լ������飬�����ǳ��ȵ����졣
long);
         set("exits", ([
             "west" : __DIR__"cl4-2",
             "south" : __DIR__"cl4-4",
             "east" : __DIR__"fanting",
]));
        set("objects",([
           __DIR__"npc/jiading" : 1,
]));
         setup();
    //     replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && me->query("family/family_name") != "����Ľ��"
	&& objectp(present("jia ding", environment(me))))
		return notify_fail("�Ҷ��ȵ�������Ľ��ɽׯ��Ҫ�Ҵ�����\n");

	return ::valid_leave(me, dir);
} 

