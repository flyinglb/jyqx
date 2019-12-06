// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "鬼门关" NOR);
	set("long", 
		"这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的\n"
                "黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再\n"
		"回阳间了。\n");
	set("exits", ([
                  "north" : "/d/death/gateway",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
//	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_sleep_room", "1");
	set("no_steal", "1");

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if( dir=="north" && !wizardp(me) )
		return notify_fail("那可是通天的路呀，你修行不够，没法走过去。\n");
	return ::valid_leave(me, dir);
}

int init()
{
        object *invs = all_inventory(this_object());
        int i,i1;
        for(i=0,i1=sizeof(invs);i<i1;i++) {
//                if( invs[i]->is_character() ) continue;
                if( userp(invs[i]) ) continue;
                if( invs[i]->query("id") == "white gargoyle" ) continue;
                invs[i]->move(VOID_OB);
                destruct(invs[i]);
        }
}

