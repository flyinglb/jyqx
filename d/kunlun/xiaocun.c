//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","С��");
	set("long", @LONG
��ν���Ӿ�����һ���տ��ĵط����˼��䷿�ݣ����ݵ��ſڶ�������һЩ
��Ƥ����������������˶����Դ���Ϊ���ġ��������ܼ������˺��٣�ֻ��һ
���Ի�װ���ĺ���������ǰ����Զ�����㣬��������������һ֧�ɿݵ���֥��
������һ��������˵����ɽ������֥���ѵ����Ի��ǲ���֥�ģ���
LONG );
	set("exits", ([
		"southeast"  : __DIR__"cunlu4",
		"westdown"  : __DIR__"shanlin1",
	]));
	set("objects", ([
		__DIR__"npc/liehu" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

