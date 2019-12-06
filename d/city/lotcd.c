// by wind

inherit ROOM;

void create()
{
	set("short", "中国体育彩票黑店");
	set("long", @LONG
这里是一间很小的房间，楼上的房间里传出来吆五喝六的赌博声。
这里一个人也没有, 一台开奖机静静地立着. 看来还没到每周开奖
的时间.要不要买一注呢(help caipiao)?
LONG
	);

	set("exits", ([
		"north" : __DIR__"duchang",
	]));

	set("objects", ([
		__DIR__"obj/lottery" : 1,
	]));

	setup();
}

