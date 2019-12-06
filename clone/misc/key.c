// key.c

inherit ITEM;

void create()
{
seteuid(getuid());
	set_name("˽��Կ��", ({"key", "yaoshi"}));
	set("long",
		"����һ���һ���˽��סլ��Կ�ס�
������������(unlock)�͹���(lock)��\n");
	set("unit", "��");
	set("weight", 10);
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
}

string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
        add_action("do_lock","lock");
	add_action("do_unlock","unlock");
}

int do_unlock()
{
	object table, bottle, rose, room, here, me = this_player();

	if (!me->query("home"))
		return notify_fail("��û˽լѽ�����⿪ʲô����\n");
	if ((string)environment(me)->query("short")!="�һ�ƺ")
		return notify_fail("���˽լ���һ������һ�ƺ�ϣ�\n");
	room = new("/d/taohuacun/obj/player");
	room -> set("short", me->query("home/home_name"));
	room -> set("long", me->query("home/home_desc")+"\n");
	if(!( here = find_object("/d/taohuacun/taohua5")) )
		here = load_object("/d/taohuacun/taohua5");
	here->set("exits/enter", file_name(room) );
	room->set("exits/out", "/d/taohuacun/taohua5" );
	table = new("/d/taohuacun/obj/table");
	bottle = new("/d/taohuacun/obj/bottle");
	rose = new("/d/taohuacun/obj/rose");
	rose -> move(bottle);
	bottle -> move(table);
	table -> move(room);
        set("sleep_room", 1);
	room->set("sleep_room",1);
	set("no_fight",1);
	room->set("no_fight",1);
	message_vision(HIG "$N�ͳ�Կ�ף�����һ���������ƿ����š�\n" NOR,me);
	return 1;
}
int do_lock()
{
	object here;
	if(!( here = find_object("/d/taohuacun/taohua5")) )
		here = load_object("/d/taohuacun/taohua5");
	here->delete("exits/enter");
	message_vision(HIG "ֻ��������һ���죬$N�ѷ��Ź����ˡ�\n" NOR, this_player());
	return 1;
}
