//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","СԺ");
	set("long", @LONG
�����������ɵ��Ӿ�ס�ķ�����һ���տ��أ���νԺ����ʵ��û��Χǽ��
һ������������������������Ĵ����Ǹ�ɽ��Ҳ�������˿���ͨ�����ﵽ���
�ġ��⡰Ժ�ӡ��ӱ�����������һ�����Ƶġ�Ժ�ӡ���
LONG );
	set("exits", ([
		"east"  : __DIR__"qipan",
		"west" :  __DIR__"xiaochufang",
		"south" : __DIR__"fangshe",
		"northup" : __DIR__"xiaoyuan2",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 3,
		__DIR__"npc/zhanchun" :1,
	]));
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

