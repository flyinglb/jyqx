inherit ROOM;

void create()
{
        set("short", "���䳡");
	set("long", @LONG
�����ǻʹ��ڲ���һ�����ܵļ�����ȴ�������������ɵ�ͭ��������䡣��
�˿��������⣬���ﻹ׼����ʳ�����ˮ��ͬʱ��������Ϣ�����Ǽ�����������
���أ�
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
	]));
        setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_ketou", "ketou");
	add_action("do_zisha", "zisha");
}
int do_ketou(string arg)
{
	object me;
	if (!arg ||arg !="yuzu") return 1;
	me = this_player();
	message_vision("$N������ȥ��\n",me);
	me->move("/d/dali/shilin");
	message_vision("$N���˹�����\n",me);
	return 1;
}
