//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","灵獒营");
	set("long", @LONG
院子很是空旷，只有在两个边角处用木条围出了两圈栅栏，拦了十多条大
狼狗。狼狗们狂叫着怒视着每一个来往的人，冲撞着那看似并不结实的木栅栏。
院子里还摆了一个木架稻草人，两个仆人正在往草人上挂鲜血淋漓的牛肉块，
一面冲着那些狼狗呲牙。
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

