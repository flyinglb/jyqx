//ROOM men1.c

inherit ROOM;

void init();
//string look_door();
int do_open(string);

void create()
{
        set("short", "���Ҵ���");
        set("long",
	     "�������Ҷ���,������һ�Ƚ��յĴ���(door)��\n"
        );
        set("outdoors", "lingjiu");
        set("exits", ([
		"west" : __DIR__"qiushi",
		"east" : __DIR__"changl11",
        ]));

	set("objects",([
                __DIR__"npc/jujian" : 1,
	]));
	set("item_desc", ([
	    "door" : (: look_door :),
        ]));

        set_temp("lock",1);
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{

	if (  (dir == "west") && objectp(present("ju jian", environment(me))) )
	 return notify_fail("�ս�������ס�㣬˵�������Բ��𣬱����صأ���أ���\n");
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_open", "open");
}

string look_door(string arg)
{
	if (query_temp("lock") == 0)
		return "���ϵ������Ѿ������ˡ�\n";
	return "�����ű�����������ס��\n";
}

int do_open(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="door")
		return notify_fail("��Ҫ��ʲô��\n");

	if( query_temp("lock") == 1 && !present("key", me) )
		return notify_fail("Կ�׶�û�У���ô���ţ�\n");

	if(!( room = find_object(__DIR__"qiushi")) )
		room = load_object(__DIR__"qiushi");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'qiushi.c' \n");

	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N��Կ�ײ�����ף�ֻ��������ડ�һ���������ˡ�\n", me);
		message("vision", "���洫��һ������������ֻ��������ડ�һ���������ˡ�\n",room);
	}
	message_vision("$N�����ƿ��ţ����˽�ȥ�����ְ�������������\n",me);
	message("vision", "�������˽��������ְ��������ˡ�\n",room);
	me->move(room);
	return 1;
}
