string look_shelf();
#define WIZ_TOC "/u/atu/txt/toc"
#define WIZ_DIR "/u/atu/txt/"

inherit ROOM;
#include <ansi.h>

void create()
{	
set("short", "阿土的工作室");
set("long", @LONG	
这里是阿土的工作室。温馨的音乐在房间里飘荡着，一台赛扬300A正在嗡嗡地工作。
墙壁上的书架(shelf)堆满了书，旁边挂着一副对联(duilian).
LONG	);	

	set("valid_startroom",1);
	set("no_steal", "1");
	set("exits", ([
		"down" : "/d/city/guangchang",
		"east" : __DIR__"neishi",
	]));
	set("item_desc", ([
		"duilian" : HIG "\n谁知盘中餐\n" NOR + HIC "粒粒皆辛苦\n" NOR,
	       "shelf" : (: look_shelf :),
	]));
	setup();
}



void init()
{
        add_action("do_read", "read");
}

string look_shelf()
{
        this_player()->start_more(read_file(WIZ_TOC));
        return "\n";
}

int do_read(string arg)
{
        object me=this_player();
        if (arg == "" || file_size(WIZ_DIR + arg+".txt") <= 0)
                return notify_fail("我们没有这本书。\n");

        me->start_more(read_file(WIZ_DIR + arg+".txt"));
        return 1;
}
