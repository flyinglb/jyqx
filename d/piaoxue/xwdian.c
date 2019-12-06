inherit ROOM;
void create()
{
        set("short", "玄武殿");
        set("long", @LONG
这里是玄武堂的活动中心，正中央端然稳坐的是玄武堂的堂主，
能坐上这个位置的一般都是跺跺脚江湖都要颤几下的人物，千
万不要轻易碰他哦！当心小命。但是如果有堂里的弟兄想当
堂主，那也只好冒死(fight)他一下了，一旦赢了，坐在这里的
————就是你。
LONG);
        set("exits", ([
		"south" : __DIR__"dayuan4",
		"east" : __DIR__"sleep4",
		"west" : __DIR__"eatroom4",
        ]));
//      set("objects", ([
//              __DIR__"npc/xwzhu":1,
//      ]) );
	setup();
}

