//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
���ɽ�����ʥ����Ƶ���һЩ����ֲ�Ļ���Ҳ���٣������Ե��αȲ���
��ʥ��ģ���Ҫ�Գ���Ĺ�ľ��С��Ϊ���������ľ������״�ֲ��������·
ͨ���ķ����������ص��ӳƴ�Ϊ�����ꡣ����������һƬ���ᣬ�����ص��ӵ�
�Ӵ����򶫶�������ʥ�ӵ��Խ�����������һ��ɽ�ȣ�����ľ��������˵��
������ȥ��������һ����ɽ��С·��������Լ���ɽ����Լ������һ�ǡ�
LONG );
	set("exits", ([
		"eastup" :  __DIR__"shijian",
		"west"   :  __DIR__"xiaoyuan1",
		"north"  :  __DIR__"houshan1",
//		"southdown":__DIR__
	]));
//	set("objects", ([
//	__DIR__"npc/binv" : 2,
//	]));
	set("outdoors","kunlun");
	setup();
	replace_program(ROOM);
}

