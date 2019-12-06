#include <room.h>
inherit CHATTING_ROOM;

void create()
{
	set("short", "资料库—玩家部");
	set("long", @LONG
这里是一间明亮的书房，房中陈设了许多书架，在很醒目的位置上挂了一面
牌子，记录着新金庸群侠II中高手的资料……
LONG );
	set("exits", ([ 
		"south" : __DIR__"shuyuan",
	]));
	set("no_fight",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
