// xiaoyuan.c
// written by tree

inherit ROOM;

void create()
{
	set("short", "十字桥");
	set("long", @LONG
眼前的景致，不由让你大吃一惊，前面居然是一个极大的荷花池，有几个姑娘正
划着小船在池中嬉戏。在这荷花池上，有一座十字桥，你悠悠然跺上了十字桥。从
这里往西就是妙香斋,东边还有一间大瓦房，而北面就是大厅了。你赶忙加快了步伐。
LONG);
	set("exits", ([ 
	"out" : __DIR__"damen",
	"west" : __DIR__"chufang",
	"north" : __DIR__"dating",
	"east" : __DIR__"kufang",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
