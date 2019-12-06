inherit ROOM;

void create()
{
	int kind=random(6);

	set_name(BHIC+HIM"民居模板"NOR);

	switch(kind)
	{
	case 0:
		set_long(@LONG
没有什么特点的平民百姓的住家。中间一张普通的木制方桌，墙边几样竹
制的日常工具，看不出主人是做什么的。
LONG);
//		set_preloads(([
//			"/map/npc/poorman": 1,
//		]));
	break;

	case 1:
		set_long(@LONG
这里好象是一个穷书生的住家，一张木桌上有笔墨，桌子后面有一个简陋
的木书架，上面摆放了一些四书五经之类的旧书。靠近窗口有一张木床，床上
的用品都已陈旧了。
LONG);
//		set_preloads(([
//			"/map/npc/shusheng": 1,
//		]));
	break;

	case 2:
		set_long(@LONG
房子的主人应该是家庭妇女，房子里都在养着小鸡小鸭什么的。一些小筐
小篮子什么的虽然多但很整洁。
LONG);
//		set_preloads(([
//			"/map/npc/woman": 1,
//		]));
	break;

	case 3:
		set_long(@LONG
这里明显是一个在役士兵的住处，床上地上到处凌乱不堪，丢了到处都是
的脏军服盔甲之类的东西。在床头还悬挂着一个没有刀的钢刀刀鞘。床上的被
子也不叠，挤在一角。床下胡乱放了几双皮靴。
LONG);
//		set_preloads(([
//			"/map/npc/guanbing": 1,
//		]));
	break;

	case 4:
		set_long(@LONG
这里是一间还算整齐的住家，墙角的木台上放了一些大包小包，还有一辆
小推车。这房子的主人常常不在家里，但明显是一个生意人。
LONG);
	break;

	default:
		set_long(@LONG
一张木桌，一张木凳，一张木床组成了这个房间，屋里不算乱，但到处都
是泥土。几样农具搁在墙边，看来住在这里的应该是一个农民。墙边的农具旁
边还有几个装满东西的麻袋，从露在外面的一些谷粒可以看出麻袋里不是种子
就是刚收获的粮食。
LONG);
//		set_preloads(([
//			"/map/npc/farmer": 1,
//		]));
	break;

	}
	init_size(2);
	init_lookout(5);
	set_exits(([
		"south":__DIR__"model01",
	]));
	setup();
}
