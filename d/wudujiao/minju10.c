// by mayue


inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����һ�������Χ�ɵļ���Ժ�䣬Զ�����ż����߲ˡ�Ժ��
�м�һ�øߴ�������Ͻ������ʺ�Ĺ�ʵ���Աߵĵ��ϸ���һ��
���Ĳ�ϯ�� 
LONG
	);
       set("outdoors", "wudujiao");

	set("exits", ([
//		"out" : __DIR__"minju7",
		"north" : __DIR__"minju6",
//		"west" : __DIR__"cun1",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
//                __DIR__"npc/xuetong": 3,
//                  __DIR__"npc/zhanglang": 1,
	]));
	set("item_desc", ([
		"��ϯ" : "\nһ�ź��Ĳ�ϯ���ڶ��ڣ������ƺ���һ���ؽѡ�\n" ,
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
        object me;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="��ϯ" ) {
		message_vision("\n$N�ƿ����ڶ��ڵĲ�ϯ������ȥ��\n", this_player());
             me->move(__DIR__"dijiao");
	      message_vision("\n���ڶ��ڵĲ�ϯһ�ƣ�$N����������������\n",me);
	}
	else {
		message_vision("\n$N˫���ڿ��бȻ��˼��£����ƺ�ʲôҲûץס��\n", this_player());
	}		
return 1;
}
