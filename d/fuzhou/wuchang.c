inherit ROOM;

void create()
{
	set("short", "�䳡");
	set("long", @LONG
�����Ǵ��������һ�����ܵ����䳡�������������ɵ�ͭ��������䡣��
�˿��������⣬���ﻹ׼����ʳ�����ˮ��ͬʱ��������Ϣ��
LONG );
	set("sleep_room",1);
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
                "/d/xiangyang/npc/obj/mudao": 1,
	]));
        setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	object me;
	if (!arg ||arg !="qiao") return 1;
	me = this_player();
	message_vision("$N�����������ϡ�\n",me);
	me->move(__DIR__"zhongzhou");
	message_vision("$N��֪���������˳�����\n",me);
	return 1;
}
