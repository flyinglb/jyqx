// /u/beyond/mr/cl5-0.c
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
��������ȥ����æ���Լ������飬������һ�㵡���������������鷿��������
���ȵ����졣
long);
         set("exits", ([
             "south" : __DIR__"cl5-1",
              "east" : __DIR__"fanting1",
             "west" : __DIR__"shufang",
]));
          set("objects",([
__DIR__"npc/guanjia1" : 1,
]));
         setup();
 //        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if (dir == "east" && me->query("family/family_name") != "����Ľ��"
	&& objectp(present("guan jia", environment(me))))
		return notify_fail("�ܼҺȵ�������Ľ��ɽׯ��Ҫ�Ҵ�����\n");

	return ::valid_leave(me, dir);
} 

