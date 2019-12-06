//Created by RoomEditer on 99-5-9.
inherit ROOM;

void create()
{
	set("short","剑冢内");
	set("long",@LONG
不多时便搬开冢上石块，露出并列着的
三柄长剑，在第一、第二两把剑之间，第一
把紫薇软剑,见长约四尺，青光闪闪，的是利
器。第二把玄铁剑剑黑黝黝的毫无异状，却
是沉重之极，三尺多长的一把剑，重量竟自
不下七八十斤，比之战阵上最沉重的金刀大
戟尤重数倍。第三把木剑拿在手□却轻飘飘
的浑似无物，年深日久，剑身剑柄均已腐朽。
LONG
	);
	set("exits",([
		"east" : "/u/liangbaoabo/jianzuo1",
	]));
	set("objects",([
		"/u/liangbaoabo/ziwei" : 1,
		"/u/liangbaoabo/tiesword" : 1,
		"/u/liangbaoabo/mujian" : 1,
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
