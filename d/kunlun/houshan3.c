//Robin 2000.5.9
//Last Modify: Byp@MX 2001.06.09

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山神庙");
	set("long", @LONG
庙宇的墙壁已经班驳，唯有庙正中的山神像还依旧完好没什么破损，据说
这是千里昆仑无数山峰中最大的一个山神庙，然而庙中供奉的山神是什么来历
恐怕已经没人能说出来了。
LONG );
	set("exits", ([
		"west" : __DIR__"houshan2",
	]));
	set("item_desc", ([
		"shanshen" : "这个山神有点古怪，手里居然拿着宝剑，试试给他磕头(ketou)会怎么样。\n",
		"山神" : "这个山神有点古怪，手里居然拿着宝剑，试试给他磕头(ketou)会怎么样。\n",
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_ketou","ketou");
}
int do_ketou(object me)
{
	int skl1;
	int skl2;
	int skl3;
	int skl4;
	me = this_player();
	skl1 = (int)me->query_skill("chess",1);
	skl2 = (int)me->query_skill("music",1);
	skl3 = (int)me->query_skill("xuantian-force",1);
	skl4 = (int)me->query_skill("zhengliangyi-sword",1);
        if (skl1<100 || skl2<100 || skl3<100 || skl4<100)
		{
		message_vision("$N对着山神的泥塑恭恭敬敬磕了一个头。\n",me);
		return 1;
		}
	else if (me->query("family/master_id") == "he zudao")
		{
		message_vision("$N对着山神的泥塑恭恭敬敬磕了一个头。\n",me);
		message_vision("山神说道：原来又是你。\n",me);
		message_vision("余音未尽，一团阴森森的烟雾笼罩过来。$N只觉得心头一紧……\n",me);
		me->move(__DIR__"difu");
		return 1;
		}
	else {
		message_vision("$N对着山神的泥塑恭恭敬敬磕了一个头。\n",me);
		message_vision("没想到山神那方向突然传来低沉的声音：\n",me);
		message_vision("“居然又是一个小三圣，那你就去阴间见你祖师去吧！”\n",me);
		message_vision("余音未尽，一团阴森森的烟雾笼罩过来。$N只觉得心头一紧……\n",me);
                if(random(3)==2)
		{
			me->unconcious();
                        me->die();
		}
		else
		{
			me->unconcious();
                        me->move(__DIR__"difu");
		}
	return 1;
	}
}

