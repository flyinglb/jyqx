inherit ROOM;

void create()
{
        set("short", "练武场");
	set("long", @LONG
这里是峨嵋的一个秘密的练武场，数个制作更为精巧的木人耸立其间。除
了可以练功外，这里还准备有食物和饮水，同时还可以休息。
LONG );
	set("sleep_room",1);
	set("objects", ([
		"/d/city3/npc/mu-ren" : 5,
		"/clone/food/jitui" : 5,
		"/clone/food/jiudai" : 2,
		"/clone/weapon/zhujian" : 1,
		"/clone/weapon/gangdao" : 1,
		"/clone/weapon/changbian" : 1,
		"/clone/weapon/gangzhang" : 1,
		"/clone/weapon/qimeigun" : 1,
		"/clone/weapon/gangjia": 1,
	]));

        setup();
//	replace_program(ROOM);
}
void init()
{
        add_action("do_zong", "zong");
}
int do_zong(string arg)
{
        object me;
        if (!arg ||arg !="shen") return 1;
        me = this_player();
        message_vision("$N纵身而起，跳进窗子。\n",me);
        me->move(__DIR__"hcaeast");
        message_vision("$N从华藏庵外跳窗进来。\n",me);
        return 1;
}
 

