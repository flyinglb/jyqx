inherit ROOM;
void create()
{
        set("short", "白虎殿");
        set("long", @LONG
这里是白虎堂的活动中心，正中央端然稳坐的是白虎堂的堂主，
能坐上这个位置的一般都是跺跺脚江湖都要颤几下的人物，千
万不要轻易碰他哦！当心小命。但是如果有堂里的弟兄想当
堂主，那也只好冒死(fight)他一下了，一旦赢了，坐在这里的
————就是你。
LONG);
        set("exits", ([
		"east" : __DIR__"dayuan2",
		"north" : __DIR__"sleep2",
		"south" : __DIR__"eatroom2",
        ]));
//      set("objects", ([
//              __DIR__"npc/bhzhu":1,
//      ]) );
	setup();
}

