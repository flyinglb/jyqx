// Room: /d/shaolin/damodong.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "·Ï¾®");
	set("long", @LONG
Õâ¿Ú¾®·ÏÖÃÒÑ¾Ã£¬ÂäÒ³°Ü²Ý£¬¶Ñ¼¯¸¯ÀÃ£¬¶¼»¯³ÉÁËÈíÄà¡£
LONG
	);

	set("exits", ([
		"out" : "/d/wizard/wizard_room",
	]));

/*
	set("objects",([
		"d/shaolin/obj/book-bamboo" : 1,
	]));
*/

	setup();
}

void init()
{
	object me = this_player();

	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("dodge", me->query("int"));
	}

}

