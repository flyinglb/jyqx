//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��Ժ");
	set("long", @LONG
������ׯ�ӵĺ�լ�ˣ�Ժ��һ��һŮ��������������Ժ���｣����Ϸ��Ժ
ǽ�߶ѻ��˺ܶ�ľ�ģ���֪��ʲô�õġ���Ժ�ӵ��ܱߣ��м������ᡣ
LONG );
	set("exits", ([
		"east"  : __DIR__"guifang",
		"west"  : __DIR__"lin1",
		"north" : __DIR__"qianting",
		"south" : __DIR__"woshi",
	]));
	set("objects", ([
		__DIR__"/npc/wuqingying" : 1,
		__DIR__"/npc/weibi" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

