//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","С����");
	set("long", @LONG
���С����Ҫ���Ǹ���������˺ܶ࣬��������Ϊ�����ʳ��Ҫ��һЩ��
Ե�ʣ����ص��Ӷ��������ʳ������ûʲô���ź򣬶����Լ����֣�����˭Ҫ
�����ã����ܻ���ǰһ��������ʣ�µĶ�����
LONG );
	set("exits", ([
		"east" :  __DIR__"xiaoyuan1",
	]));
	set("objects", ([
		__DIR__"obj/shaobing" : 3,
		__DIR__"obj/wan" : 1,
	]));
	setup();
	replace_program(ROOM);
}

