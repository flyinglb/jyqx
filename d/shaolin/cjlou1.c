// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "藏经阁二楼");
	set("long", @LONG
千余年来少林寺执中原武林之牛耳，自达摩老祖以下，历代
人材辈出。其中有不少高僧遗著留存，汇集至今，终成名震天下
的少林七十二绝艺。少林精华，尽集于此。二楼四面开窗，确保
通风。中间排列着五排大书架。四周则陈列矮几，以供阅读。几
位老僧手执经卷，正在闭目凝思。
LONG );
	set("exits", ([
                "down" : __DIR__"cjlou",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-zhen" : 1,
		"/clone/book/yijinjing" : 1,
		"/clone/book/wuji1" : 1,
		"/clone/book/wuji2" : 1,
		"/clone/book/wuji3" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if (!present("yijin-jing",this_object()) )
		return notify_fail("镇寺之宝易筋经不见了, 你怎能就走呢！\n");
        if( present("yijin-jing", me))
                return notify_fail("镇寺之宝易筋经不见了, 你怎能就走呢！\n");
	if ( present("huizhen zunzhe", environment(me)) )
	if ( present("shaolin-wuji", me)
	||   objectp(ob = present("corpse", me)) && present("shaolin-wuji", ob) )
	{
		if (dir == "down" )
		{
			return notify_fail("慧真说道: 武功秘籍只许在藏经阁内研习，不得携带外出 !\n");
		}
	}
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_ansuan","ansuan");
        add_action("do_give","give");
        add_action("do_put","put");
        add_action("do_disc", ({"sell","pawn","dang","buy","list","shu","check","value","gujia","redeem"}));
//	add_action("do_get","get");
}
int do_ansuan(string arg)
{
        write(this_player()->query("name")+"，面对那么多佛经，你心里不敢做这样的事了！\n");
        return 1;
}
int do_give(string arg)
{
        write(this_player()->query("name")+"，你想栽赃？\n");
        return 1;
}
int do_put(string arg)
{
        write(this_player()->query("name")+"，这里的东西请不要放到别处去！\n");
        return 1;
}
int do_get(string arg)
{
       object ob = present(arg, this_object());
       if( objectp(ob) && ob->is_character() ) {
	write(this_player()->query("name")+"，别在这里害人。\n");
	return 1;
        }
        return 0;
}

int do_disc(string arg)
{
write("你想干什么?\n");
return 1;
}
