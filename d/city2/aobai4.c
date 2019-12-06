// Room: /city2/aobai4.c


inherit ROOM;
void close_gate();
int do_open(string arg);
int do_close(string arg);

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
������������Ժ��������һ����԰������һ�������ߵ�ֱ
ͨ�����ݵ��Է����м����ٱ����ء��������鷿���ϱ�������˽
����η�,����(men)�����ŵġ�
LONG );
	set("item_desc", ([
		"men":"����һ�Ⱥܽ�ʵ�����š�\n",
	]));
	set("exits", ([
		"west" : __DIR__"aobai6",
		"east" : __DIR__"aobai3",
		"north" : __DIR__"aobai7",
	]));

	set("objects", ([
		"/d/city2/npc/guanjia" : 1,
		"/d/city/npc/jiading" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"aobai8")) )
		room = load_object(__DIR__"aobai8");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n",this_object());
                message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n" ,
			 this_object());
		room->delete("exits/north");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n",room);
	        message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" ,
			room );
	}
}

int do_open(string arg)
{
	object room;
        object ob;

	if (query("exits/south"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "men" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("lfkey", this_player())))
		return notify_fail("�㲻��������\n");
	if ( userp(ob) ) return notify_fail("�������ף�\n");
	message_vision(
	"$N��һ��Կ�״������ţ�����Կ��ȴ����.\n", this_player());
	destruct(ob);

       if(!( room = find_object(__DIR__"aobai8")) )
		room = load_object(__DIR__"aobai8");
	if(objectp(room))
	{
		set("exits/south", __DIR__"aobai8");
		message_vision("$Nʹ���Ѱ��Ŵ��˿�����\n",this_player());
		room->set("exits/north", __FILE__);
		message("vision","�������˰Ѱ��Ŵ��ˡ�\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

int valid_leave(object me, string dir)
{
	if (objectp(present("guan jia", environment(me))) && 
                     (dir == "south"||dir == "north")&& living(present("guan jia", environment(me))))
		return notify_fail("Ů�ټҵ�ס���㡣\n");
	return ::valid_leave(me, dir);
}

