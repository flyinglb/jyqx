inherit ROOM;
void create()
{
        set("short", "飘雪楼一楼");
        set("long", @LONG
这里是飘雪山庄的中心，你隐约可以听到有人好象在
和你说话，东南西北分别是青龙，朱雀，白虎，玄武
四堂，楼上是飘雪山庄的长老院、执法堂和护法堂。
如果你不是飘雪山庄的人，请尽快离开。
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
	        set("exits", ([
                "east"  : __DIR__"qinglong",
                "west"  : __DIR__"baihu",
                "south"  : __DIR__"zhuque",
                "north"  : __DIR__"xuanwu",
                "southwest"  : __DIR__"piaoxie",
                "southeast"  : __DIR__"shenlong",
                "up"  : __DIR__"piaoxue2",
        ]));
        setup();
}
void init ()
{
   add_action("do_listen", "listen");
}

int do_listen(string arg)
{
   object me;
   me = this_player();

   tell_object(me,"庄主有令，非飘雪弟子，到此止步，违令者格杀无论\n");
   message("vision",me->name(me)+"突然住足，似乎在侧耳倾听着什么。\n", environment(me),me);
   return 1;
}