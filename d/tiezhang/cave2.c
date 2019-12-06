//room: /d/tiezhang/cave2.c

inherit ROOM;

void init();
int do_lingwu(string);

void create()
{
        set("short","密洞");
        set("long",@LONG
这里似乎是传说中的铁掌帮练功的地方，到处黑黑的看不太清楚，隐约间
能看到一点洞壁上有一些奇怪的的图(tu)，你想，在这上面是不是可以领
悟(kan)出什么呢？
LONG );
        set("exits",([
                "out" : __DIR__"dong-2",
        ]));
        set("item_desc",([
                "tiesuo" : "图案很特别不知道有什么作用。\n" ,
        ]));
        setup();
}

void init()
{
        add_action("do_lingwu","kan");
}

int do_lingwu(string arg)
{
        object ob;
        int c_skill;
        int exp;
        ob = this_player();
        exp=(int)ob->query("combat_exp");

        if (arg != "tu") return 0;
        c_skill=(int)ob->query_skill("strike", 1);

        if (ob->query("jing")<200)
                return notify_fail("你太累了，无法领悟到什么。\n");
//      if (c_skill< 250)
//              return notify_fail("你对着洞壁琢磨了良久，无法从上面领悟到什么。\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("jing", 80);
                return notify_fail("你的经验不够，无法继续领悟什么了。\n");
        }

        message_vision("$N仔细的看着图，恍惚间似乎领悟到了什么。\n",ob);
        ob->improve_skill("strike", random(100*ob->query_int()));
        ob->receive_damage("jing", 150);
        return 1;
}

