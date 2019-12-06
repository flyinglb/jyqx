//      dadian.c 大殿
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","大殿");
        set("long",@LONG
这里是雪山寺的大殿，中央供奉着佛祖塑像。僧人们在念着
经文。远来的香客们在这里虔诚地膜拜(mobai)。大殿两侧都是
侧殿。
LONG );
        set("exits",([
                "east"  : __DIR__"cedian1",
                "west"  : __DIR__"cedian2",
                "south" : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/lazhang" : 1,
		__DIR__"npc/xiang-ke" : 2,
        ]));
        set("valid_startroom", 1);
//      set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);

        "/clone/board/xueshan_b"->foo();
}
void init()
{
        add_action("do_mobai","mobai");
}
int do_mobai(string arg)
{
        object ob;
        int c_skill;
        ob = this_player();

//      if (arg != "dao") return 0;
        c_skill=(int)ob->query_skill("lamaism", 1);

        if (ob->query("jing")<20)
        {
                message_vision("$N太累了，没有精神膜拜。\n",ob);
                return 1; 
        }
        if (c_skill> 300)
        {
                message_vision("$N觉得无法通过膜拜来提高密宗修为了。\n",ob);
                return 1; 
        }
        if (c_skill< 100)
        {
                message_vision("$N对密宗的境界领悟得不够，无法通过膜拜来提高密宗修为。\n",ob);
                return 1; 
        }

        message_vision("$N面对佛像、虔诚膜拜，对密宗心法似有所悟。\n",ob);
        ob->improve_skill("lamaism", random(10*ob->query("int")));
        ob->receive_damage("jing", 5);
        return 1;
}
