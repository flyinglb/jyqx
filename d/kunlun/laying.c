//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����Ӫ");
	set("long", @LONG
Ժ�Ӻ��ǿտ���ֻ���������߽Ǵ���ľ��Χ������Ȧդ��������ʮ������
�ǹ����ǹ��ǿ����ŭ����ÿһ���������ˣ���ײ���ǿ��Ʋ�����ʵ��ľդ����
Ժ���ﻹ����һ��ľ�ܵ����ˣ��������������������Ϲ���Ѫ�����ţ��飬
һ�������Щ�ǹ�������
LONG );
	set("exits", ([
		"east"  : __DIR__"xxfang",
		"north" : __DIR__"huilang",
	]));
	set("objects", ([
		"/d/city/npc/wolfdog" : 4,
		__DIR__"npc/zhujiuzhen" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

