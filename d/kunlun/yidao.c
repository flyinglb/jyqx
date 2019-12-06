//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","弈道厅");
	set("long", @LONG
昆仑三圣的三种绝技到今天恐怕就剩下一门剑道了，看这厅中那枰落满灰
尘的棋盘就可窥一斑。棋盘(qipan)上还摆着不知是不是何足道自己和自己下
的一局没下完的棋。
LONG );
	set("exits", ([
		"east"  : __DIR__"sanshengju",
	]));
	set("item_desc", ([
		"qipan" : "这是一个盘没有下完的棋可以下棋(xiaqi)。\n",
	]));
	setup();
}
void init()
{
	add_action("do_xiaqi","xiaqi");
}
int do_xiaqi(object me)
{
	int skl;
	me = this_player();
	skl = (int)me->query_skill("chess",1);
	if (me->query("jing")<70)
		return notify_fail("你太累了，无法集中精力下棋。\n");
	if (skl < 40)
		return notify_fail("你的棋艺还不到，无法领会这盘棋的境界。\n");
	if (skl > 150)
		return notify_fail("你已经无法从这盘棋上学到什么了。\n");
	if(time() - (int)me->query_temp("last_chess_time") < (3 - random(2)))
		return notify_fail("你上一步还没下好，就想好下一步了？\n");
	message_vision("$N冥思苦想，缓缓下了一步棋，对围棋又有了更深刻的体会。\n", me);
	me->set_temp("last_chess_time",time());
	me->improve_skill("chess", random(50 * me->query_int()));
	me->receive_damage("jing", 50);
	return 1;
}
