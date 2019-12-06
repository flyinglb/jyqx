//room: /d/xingxiu/cave2.c

inherit ROOM;

void init();
int do_lingwu(string);

void create()
{
	set("short","无底洞");
	set("long",@LONG
这里似乎是传说中的无底洞，到处黑黑的看不太清楚，隐约间能看到
一点洞壁上有一些古怪的人型图案(tu)，你想，在这上面是不是可以领悟
(lingwu)出什么呢？
LONG );
	set("exits",([
		"out" : __DIR__"cave",
	]));
	set("item_desc",([
		"tiesuo" : "图案上刻着很多小人，手里拿着什么在挥舞，不知道能不能算是一种武功。\n" ,
	]));
	setup();
}

void init()
{
	add_action("do_lingwu","lingwu");
}

int do_lingwu(string arg)
{
	object ob;
	int c_skill;
	int exp;
	ob = this_player();
	exp=(int)ob->query("combat_exp");

	if (arg != "tu") return 0;
	c_skill=(int)ob->query_skill("blade", 1);

	if (ob->query("jing")<100)
		return notify_fail("你太累了，无法领悟到什么。\n");
	if (c_skill< 250)
		return notify_fail("你对着洞壁琢磨了良久，无法从上面领悟到什么。\n");
	if (exp*10 <= (c_skill*c_skill*c_skill)) {
		ob->receive_damage("jing", 50);
		return notify_fail("你的经验不够，无法继续领悟什么了。\n");
        }

	message_vision("$N跌坐良久，恍惚间似乎领悟到了什么。\n",ob);
        ob->improve_skill("blade", random(50*ob->query("int")));
        ob->receive_damage("jing", 70);
        return 1;
}
