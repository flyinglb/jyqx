// by mayue


inherit ROOM;

void create()
{
	set("short", "�ؽ�");
	set("long", @LONG
����һ�������ĵؽѣ�ͷ����һ�Ų�ϯ��ס�˹��ߡ��ؽ���
�����һЩ׼��������ʳ�������Ķѷ���ľ���ϡ�
LONG
	);
//     set("outdoors", "wudujiao");

	set("exits", ([
//		"out" : __DIR__"minju7",
//		"north" : __DIR__"minju6",
//		"west" : __DIR__"cun1",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
                __DIR__"obj/shibing": 2,
                __DIR__"obj/huluobu": 1,
                __DIR__"obj/tudou": 1,
	]));
	set("item_desc", ([
		"��ϯ" : "\nһ�ź��Ĳ�ϯ���ڶ��ڣ���ס����������⡣\n" ,
	]));
	setup();
//	replace_program(ROOM);
}
void init()
{
        add_action("do_move", "pull");
}
int do_move(string arg)
{
//        object me,hole;
        object me;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="��ϯ" ) {
//            hole = new(__DIR__"minju10");
		message_vision("\n$N�ƿ����ڶ��ڵĲ�ϯ������ȥ��\n", this_player());
             me->move(__DIR__"minju10");
	      message_vision("\n���ڵ��ϵĲ�ϯ��Ȼһ�ƣ�$N���������˳�����\n",me);
	}
	else {
		message_vision("\n$N˫���ڿ��бȻ��˼��£����ƺ�ʲôҲûץס��\n", this_player());
	}		
return 1;
}
