// Room: /d/city/wumiao.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "武庙");
	set("long", @LONG
这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的
横匾。殿两侧壁上嵌着“尽忠报国”四个大字。武人到此，都放下武器，毕恭
毕敬地上香礼拜。旁边似乎有一道侧门。
LONG
	);
	set("no_sleep_room", 1);
	set("item_desc", ([ /* sizeof() == 1 */
	  "northwest" : (: look_door,     "northwest" :),
]));
	set("no_steal", 1);
	set("no_fight", 1);
	set("exits", ([ /* sizeof() == 3 */
         "up" : __DIR__"ren",
	  "northwest" : "/d/wizard/guest_room",
	  "east" : __DIR__"beidajie2",
	]));
	
	set("objects", ([ /* sizeof() == 1 */
	  __DIR__"obj/box" : 1,
	]));
      	
	create_door("northwest","竹门","southeast",DOOR_CLOSED);
	set("no_clean_up", 0);
	set("valid_startroom", 1);

	setup();
}
void init()
{
//      object me;
//      me=this_player();
//      me->set("startroom",base_name(environment(me)));
        add_action("do_dazuo", "dazuo");
        add_action("do_tuna", "tuna");
        add_action("do_sleep", "sleep");
        return;
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
