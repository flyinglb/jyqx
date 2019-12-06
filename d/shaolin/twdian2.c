// Room: /d/shaolin/twdian2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "西侧殿");
	set("long", @LONG
这里是西侧殿。房间四周悬挂着达摩祖师、观音大士的画
像，以及一些寺内元老的字画。地下散乱地放着许多蒲团，木
鱼等。看来此处是本派弟子打坐修行之所。几位中年和尚手持
数珠，正在敲打木鱼喃喃念经(nian fojing)。
LONG );
	set("exits", ([
		"east" : __DIR__"twdian",
//                "west" : "/u/simon/room/jingshi",
	]));
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}
void init()
{
        add_action("do_nian", "nian");
}
int do_nian(string arg)
{
        object ob;
        int c_skill;
        ob = this_player();

        if (arg != "fojing") return 0;
        c_skill=(int)ob->query_skill("buddhism", 1);

        if (ob->query("jing")<40)
        {
                message_vision("$N太累了，没有力气再敲打木鱼。\n",ob);
                return 1; 
        }
        if (c_skill> 300)
        {
                message_vision("$N觉得无法通过敲木鱼念佛经来提高佛学修为了。\n",ob);
                return 1; 
        }
        if (c_skill< 100)
        {
                message_vision("$N似乎对佛经领悟得不够，无法背诵佛经来提高佛学修为。\n",ob);
                return 1; 
        }

        message_vision("$N敲打着木鱼、虔心念颂学习过的佛经，对禅宗心法似有所悟。\n",ob);
        ob->improve_skill("buddhism", random(50*ob->query("int")));
        ob->receive_damage("jing", 30);
        return 1;
}


