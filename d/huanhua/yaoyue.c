// liangong4.c

inherit ROOM;

void create()
{
	set("short", "邀月楼");
	set("long", @LONG
小楼的匾额上写着“邀月楼”，这里是剑庐中最高之处。上得楼来，举目四望，
整个剑庄一览无余，那漂叶的溪畔，那柳荫的水边，那浣溪纱的丽人，那嬉戏在河
岸的孩子，那鸡犬相闻于耳的风景人情……
LONG
	);
        set("exits", ([ 
		"north" : __DIR__"huajing",
					
        ]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",0);
	setup();
	replace_program(ROOM);
}
