//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ʥ��");
	set("long", @LONG
�������̲����𣬵��������㻨�������벻������ĺ�֮����Ȼ�����
�õط���ԭ�������Ĵ����ǲ����ɽ����ס�˺������������ص��Ӷ���������
�����ø�������������滨��������װ�����ش�������ɽ�ϵ�һ������ʤ�ء�
LONG );
	set("exits", ([
		"north"  : __DIR__"sanshengju",
		"southup"  : __DIR__"shanlu7",
	]));
	set("objects", ([
		__DIR__"npc/xihuazi" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

