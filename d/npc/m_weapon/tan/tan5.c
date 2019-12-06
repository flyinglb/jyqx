//tan5.c

inherit ROOM;
void init();
int do_push(string);
void create()
{
	set("short", "�����Ϻ� ");
	set("long",
		"�����Ǽ����Ϻ��ף����ܺں����ģ�ͷ���Ͽ�����һ�����⣬��ߵ�ˮ��\n"
		"���Ϻ��µ�ӿ���š���������һ�����ۡ������ƺ���һ�����⣬��һ��޴�\n"
		"��ʯ��(stone)���š���ΧһƬ���ţ��ƺ������Ų��ɱ����\n"

	);
	set("exits", ([
		"up" : __DIR__"tan6",	
		"west" : __DIR__"tan7",
		"south" : __DIR__"tan7",
		"north" : __DIR__"tan7",
	]));
	set("item_desc", ([
		"stone": 
"\n����һ��޴��ʯͷ���������ʵ��������ҵģ��Ե�ʮ�ֵļ�Ӳ����������������һ��\n"
"(push)��ʯͷ����һ�£������ֻص�ԭ���ˡ����ƿ�һ˲�䣬���㱿������ƹ��ߴ���\n"
"��Ͷ���������������һ������һ�����졣\n"
        ]) );
	setup();
}

void init()
{	
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();
	object room;

	if ((arg !="stone" || !arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if ((int)me->query_skill("dodge") < 50 ) {
		me->add_temp("tmark/��",1);
		write("��Ȼһ�����������������һ�����ģ����һ�������ã�\n");
		message("vision","ǰ�����Ӱ������Ȼһ�Σ���������׹ȥ���������׶༪����!\n",
			environment(me), ({me}) );
		me->unconcious();
		me->move("/d/taohua/haitan");
		message_vision("����һ��ӿ�����һ���˱�����������\n", me);
		return 0;
		}
	
	if (!( room = find_object(__DIR__"cave")) )
		room = load_object(__DIR__"cave");
	if (!query("exits/east"))
		{
		set("exits/east", __DIR__"cave");
		message_vision("$N�Ѿ�ʯ�Ƶ�һ�ߣ�¶��һ�����ڣ��������ĵ���Щ������\n",me);
		room -> set("exits/west", __FILE__);
		message("vision", "���洫��һ���ƶ���ʯ��¡¡��������\n",room);
		}
	else
	 {
		delete("exits/east");
		message_vision("ˮ��һ��ӿ������ʯ��¡һ��������ԭ���������ֱ���ס�ˡ�\n",me);
		room -> delete("exits/west");
		message("vision","���洫��һ�����죬���ڱ���ס�ˡ�\n", room);
	}
	return 1;
}
