// /u/beyond/mr/xiaoting.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"С��"NOR);
	set("long",@long
���߽����СС������, �����������һ����̴ľ�輸�ͼ�����������
�ӣ���̴ľ�Ĳ輸�ϰڷ��Ų���ͼ�ֻ���񱭣�ר���������á����̲�ס��
���������ϣ���ƣ�������ĵõ���ֵ���Ϣ��
long);
         set("exits",([
             "east" : __DIR__"xiangfang",
             "north" : __DIR__"chufang",
             "south" : __DIR__"houtang",
             "west" : __DIR__"xiaojing4",
]));
set("objects",([
__DIR__"npc/abi" : 1,
__DIR__"obj/xiangcha" : 2,
]));
         setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "north" && me->query("family/family_name") != "����Ľ��"
	&& objectp(present("a bi", environment(me))))
		return notify_fail("���̺ȵ�������Ľ��ɽׯ��Ҫ�Ҵ�ѽ����\n");

	return ::valid_leave(me, dir);
} 

