// /d/wizard/guest_room.c
// modified by wind

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "巫师会客室");
	set("long", @LONG
这里是巫师和玩家交流的地方，如果你有什么问题需要向巫师请
教，可以在这里留言(post)。不过如果问题牵涉到解谜或者已经在帮
助文件里有详细说明，巫师们就不一定会回答。楼上是巫师休息室，
一般玩家到这里后就上不去了。
LONG
	);

	set("exits", ([
		"up": __DIR__"wizard_room",
		"southeast": "/d/city/wumiao" ]));
	set("no_fight", 1);
//	set("no_get", "1");
	create_door("southeast", "竹门", "northwest", DOOR_CLOSED);

	setup();
	call_other("/clone/board/towiz_b", "???");
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
		return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

void init()
{
      object tingyu_room=find_object("/d/city2/tingyu");
       if (!userp(this_player())) return;
      if (!objectp(tingyu_room))
          tingyu_room=load_object("/d/city2/tingyu");
         add_action("do_dazuo", "dazuo");
        add_action("do_tuna", "tuna");
        add_action("do_sleep", "sleep");
}
 int do_dazuo(string arg)
{
        write("在这里你无法静心运气。\n");
        return 1;
}
int do_tuna(string arg)
{
        write("在这里你无法修身养气。\n");
        return 1;
}
int do_sleep(string arg)
{
        write("在这里你怎么也睡不着。\n");
        return 1;
}
