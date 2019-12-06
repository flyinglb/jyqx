//Room: sheshenya.c 舍身崖
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","舍身崖");
	set("long",@LONG
这是一处险峻的悬崖峭壁，相传真武帝在此舍身得道。崖上立有铁栅栏，
防止有人自杀步真武帝的后尘。不过这里后来却成了武当弟子练习轻功的好场
所，你可以试试爬悬崖(climb xuanya)，不过轻功太差的可别乱试哟。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east"     : __DIR__"nanyanfeng",
	]));
	set("outdoors", "wudang");
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object ob;
        int c_skill;
        ob = this_player();

        if (arg != "xuanya") return 0;
        c_skill=(int)ob->query_skill("dodge", 1);

        if (ob->query("qi")<50)
        {
                message_vision("$N太累了，没法爬上悬崖的了。\n",ob);
                return 1; 
        }
        if (c_skill> 200)
        {
                message_vision("$N轻功够好了，再爬也没用了。\n",ob);
                return 1; 
        }
        if (c_skill< 100)
        {
                message_vision("$N轻功太差了，无法提气爬上这个悬崖的。\n",ob);
                return 1; 
        }

        message_vision("$N纵身爬上悬崖，往返纵横几次，感觉身法灵活了一些。\n",ob);
        ob->improve_skill("dodge", random(50*ob->query("int")));
        ob->receive_damage("qi", 25);
        return 1;
}
