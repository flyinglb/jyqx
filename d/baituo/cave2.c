inherit ROOM;

void create()
{
	set("short", "�ڶ�");
	set("long", @LONG
������ɽ�����һ�����ܵ����䳡�������������ɵ�ͭ��������䡣��
�˿��������⣬���ﻹ׼����ʳ�����ˮ��ͬʱ��������Ϣ��
LONG );
	set("exits", ([
		"south"     : __DIR__"cave1",
	]));
	set("sleep_room",1);
/*
	set("objects", ([
		"/d/baituo/npc/tong-ren" : 5,
		"/clone/food/jitui" : 5,
		"/clone/food/jiudai" : 2,
		"/clone/weapon/zhujian" : 1,
		"/clone/weapon/gangdao" : 1,
		"/clone/weapon/changbian" : 1,
		"/clone/weapon/gangzhang" : 1,
		"/clone/weapon/qimeigun" : 1,
		"/clone/weapon/gangjia": 1,
	]));
*/
        setup();
	replace_program(ROOM);
}
 

