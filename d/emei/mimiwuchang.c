inherit ROOM;

void create()
{
        set("short", "���䳡");
	set("long", @LONG
�����Ƕ��ҵ�һ�����ܵ����䳡������������Ϊ���ɵ�ľ��������䡣��
�˿��������⣬���ﻹ׼����ʳ�����ˮ��ͬʱ��������Ϣ��
LONG );
	set("sleep_room",1);
	set("objects", ([
		"/d/city3/npc/mu-ren" : 5,
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
        add_action("do_zong", "zong");
}
int do_zong(string arg)
{
        object me;
        if (!arg ||arg !="shen") return 1;
        me = this_player();
        message_vision("$N��������������ӡ�\n",me);
        me->move(__DIR__"hcaeast");
        message_vision("$N�ӻ�����������������\n",me);
        return 1;
}
 

