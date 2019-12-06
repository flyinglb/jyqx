// Room: eastroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ���ּ�ʵ����ʯ������ϡ��ϱ߿���ͨ�򶫳��ţ�·��
��һ����ª�Ĳ�̯��һ��ϴ�÷����˵ľɷ���������ͷ������������
�⣬һ�ų����Ϸ��ż�ֻ��Ŵִ��� (Wan)������ʢ���ſɿڵĲ�ˮ��
    ������ͨ������֣�������һ��������ﴫ������ȭ�����֡�
LONG );
        set("outdoors", "chengdu");
        set("resource/water", 1);
        set("item_desc", ([
                "wan" : "������Ĵ���裬��һ��ɣ�\n",
        ]));
	set("exits", ([
	    "northeast" : __DIR__"jiudian",
	    "northwest" : __DIR__"northroad3",
	    "south"     : __DIR__"eastroad2",
	]));
	set("objects", ([
	    __DIR__"npc/xiaozei" : 1,
	    __DIR__"obj/jiao" : 1,
	]));
//        set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_drink","drink");
}
int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water)
	{
		me->set("water", current_water+60);
		message("vision", me->name()
		+"����һ���ˮ��.... \n", environment(me), ({me}) );
	write("�����һ���ˮ��.����.����..���˸��ɾ�������ѽ��\n");
	}
	else write("��ʵ���ǺȲ����ˡ�\n");
	return 1;
}
