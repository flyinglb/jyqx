//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��Ժ");
	set("long", @LONG
һ�����Ǻܴ��Ժ�ӣ�Ժ����Χ�м������ᣬ������һ����԰��Ժ������
ֲ���ɰ���ͩ���м��軨����������ķ���ǰ��
LONG );
	set("exits", ([
		"east"  : __DIR__"yashi",
		"south" : __DIR__"zhengfang1",
		"north" : __DIR__"neizhai",
		"northwest" : __DIR__"hhyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

