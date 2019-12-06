// sanqingdian.c 三清殿
// by Xiang

inherit ROOM;

void create()
{
        set("short", "三清殿");
        set("long", @LONG
这里是凌霄宫的三清殿，是武当派会客的地点。供着元始天尊、太上道
君和道德真君的神像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着几
个蒲团，有几个道士和参拜香客在冥想虚空静心修道(xiu dao)。东西两侧
是走廊，北边是练武的广场，南边是后院。
LONG );
        set("valid_startroom", 1);
        set("exits", ([
                "north" : __DIR__"guangchang",
                "south" : __DIR__"houyuan",
                "east"  : __DIR__"donglang1",
                "west"  : __DIR__"xilang",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/guxu" : 1,
                CLASS_D("wudang") + "/song" : 1
        ]));
//        set("no_clean_up", 0);
        setup();
        "/clone/board/wudang_b"->foo();
}

void init()
{
        add_action("do_xiu", "xiu");
}
int do_xiu(string arg)
{
        object ob;
        int c_skill;
        ob = this_player();

        if (arg != "dao") return 0;
        c_skill=(int)ob->query_skill("taoism", 1);

        if (ob->query("jing")<20)
        {
                message_vision("$N太累了，没有精神冥想虚空。\n",ob);
                return 1; 
        }
        if (c_skill> 300)
        {
                message_vision("$N觉得无法通过冥想修道来提高道家修为了。\n",ob);
                return 1; 
        }
        if (c_skill< 100)
        {
                message_vision("$N似乎对老子的境界领悟得不够，无法冥想修道来提高道家修为。\n",ob);
                return 1; 
        }

        message_vision("$N冥想虚空、静心修道，对道学心法似有所悟。\n",ob);
        ob->improve_skill("taoism", random(10*ob->query("int")));
        ob->receive_damage("jing", 5);
        return 1;
}
