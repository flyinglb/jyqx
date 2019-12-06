inherit ROOM;
void create()
{
        set("short", "青龙殿");
        set("long", @LONG
这里是青龙堂的活动中心，正中央端然稳坐的是青龙堂的堂主，
能坐上这个位置的一般都是跺跺脚江湖都要颤几下的人物，千
万不要轻易碰他哦！当心小命。但是如果有堂里的弟兄想当
堂主，那也只好冒死(fight)他一下了，一旦赢了，坐在这里的
————就是你。
LONG);
        set("exits", ([
		"west" : __DIR__"dayuan1",
		"south" : __DIR__"sleep1",
		"north" : __DIR__"eatroom1",
        ]));
//      set("objects", ([
//              __DIR__"npc/qlzhu":1,
//      ]) );
	setup();
}

