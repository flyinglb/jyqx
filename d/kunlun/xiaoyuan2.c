//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","СԺ");
	set("long", @LONG
�����������ɵ��Ӿ�ס�ķ���������һ���տ��أ���νԺ����ʵ��û��
Χǽ��һ������������������������Ĵ����Ǹ�ɽ��Ҳ�������˿���ͨ������
������ġ��⡰Ժ�ӡ���������������һ�����Ƶġ�Ժ�ӡ���
LONG );
	set("exits", ([
		"southdown" :  __DIR__"xiaoyuan1",
		"north" : __DIR__"kefang",
		"west" : __DIR__"sleeproom",
		"east" : __DIR__"playroom",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 3,
		__DIR__"npc/suxi" :1,
	]));
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

