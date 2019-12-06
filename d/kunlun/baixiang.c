//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","白象山");
	set("long", @LONG
崎岖的山林小路途经了这座冰雪覆盖的山峰，抬眼向上望，白茫茫一片，
看不清山上有什么。而这座山看起来就这里是坡势最缓的了，若没有向导指点
想要上山恐怕是不太好办的了。山路还在延伸，远远望去，还是山和林交织的
无限。
LONG );
	set("exits", ([
		"southeast"  : __DIR__"shanlin2",
		"northwest"  : __DIR__"shanlin3",
//		"eastup" : __DIR__"shanbi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}
void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
	object me=this_player();
	if (arg != "shan") return 0;
	message_vision(HIW
"$N走到山坡下，试图爬上山去！\n"NOR,me);
	if ((int)me->query_dex() < 40)
	{
		message_vision(HIR
"$N一下失手，从山坡上摔了下来……\n"NOR,me);
		me->set("qi",10);
		me->set("jing",10);
		me->unconcious();
		return 1;
	}
	if (!(int)me->query_temp("灵芝")) 
	{
	message_vision(HIB "$N始终找不到可以爬上去的路，只好悻然作罢。\n"NOR,me);
                return 1;
        }
        message_vision(HIW
"$N手足并用地爬到了一个较高的地方。\n"NOR,me);
        me->move(__DIR__"shanbi");
	me->delete_temp("灵芝");
        return 1;
}
