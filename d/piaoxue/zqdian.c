inherit ROOM;
void create()
{
        set("short", "朱雀殿");
        set("long", @LONG
这里是朱雀堂的活动中心，正中央端然稳坐的是朱雀堂的堂主，
能坐上这个位置的一般都是跺跺脚江湖都要颤几下的人物，千
万不要轻易碰他哦！当心小命。但是如果有堂里的弟兄想当
堂主，那也只好冒死(fight)他一下了，一旦赢了，坐在这里的
————就是你。
LONG);
        set("exits", ([
		"north" : __DIR__"dayuan3",
		"east" : __DIR__"sleep3",
		"west" : __DIR__"eatroom3",
        ]));
//      set("objects", (
//              __DIR__"npc/zqzhu":1,
//      ]) );
	setup();
}

