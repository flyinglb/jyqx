inherit ROOM;

void create()
{
        set("short", "���䳡");
	set("long", @LONG
�����Ǵ�ѩɽ��һ��ɽ�꣬ȴ�������������ɵ�ͭ��������䡣��
�˿��������⣬���ﻹ׼����ʳ�����ˮ��ͬʱ��������Ϣ������ɽ�껹������
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
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	object me;
        if (!arg ||arg !="shanpo") return 1;
	me = this_player();
        message_vision("$N��ɽ����������ȥ��\n",me);
        me->move("/d/xuedao/nroad4");
        message_vision("$N�������˹�����\n",me);
	return 1;
}
