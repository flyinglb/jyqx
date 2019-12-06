inherit ROOM;

void create()
{
	set("short", "海边礁石");
	set("long", @LONG
这是一片空旷的海滩，却有着无数大型的礁石(jiaoshi)耸立其间，你徘徊
在礁石前的海滩上，心里在想有没有可能跳(tiao)得上这片礁石。
LONG
	);
	set("outdoors","taohua");
	set("exits", ([
		"west" : __DIR__"haitan",
	]));
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_tiao", "tiao");
}

int do_tiao(string arg)
{
//	object weapon;
	object me=this_player();
	int dodgeskill=(int)me->query_skill("dodge", 1);
	int exp=(int)me->query("combat_exp");
 
	if( !arg || arg != "jiaoshi")
		return notify_fail("你想跳到海里？\n");
	if( me->query("qi") < (int)(me->query("max_qi")/5))
		return notify_fail("再跳下去你会累死的！\n");
	else
	{
	message_vision("$N纵身跳起，在礁石上纵横数次而返。\n", me);
	if (exp*10 <= (dodgeskill*dodgeskill*dodgeskill))
		{
			me->receive_damage("qi", 30);
			return notify_fail("你的经验不够，再跳跃也不能提高什么了。\n");
		}
		if (dodgeskill<(int)me->query_skill("literate",1))
		{
			me->improve_skill("dodge", random((int)(me->query("int")
				+me->query_skill("dodge")*2)));
			tell_object(me, "你从中领悟出一些轻功方面的窍门。\n");
		}
		else
		{
			tell_object(me, "你费了半天劲，可是什么也没有学到。\n");
		}
	}
	me->receive_damage("qi", 50);
	return 1;
}

