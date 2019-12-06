//room: huanyuan.c
inherit ROOM;
void init();
int do_move(string arg);
int do_enter(object me);

void create()
{
  set("short","��԰");
  set("long",@LONG
�����ǰ������һ�������Ļ�԰����԰������һЩ������������Լ��
��Ʈ���ٻӰ�����ǹ��еĽ���������ˣ����԰������һ����ɽ(jiashan)��
��԰�Ķ�����ͷ�ǳ��ȣ�������һ��С��ͨ����ɽͯ������֮����
LONG );
  set("exits",([
      "west" : __DIR__"changl1",
      "north" : __DIR__"xiaodao1",
      "east" : __DIR__"changl2",
      "south" : __DIR__"changl15",
  ]));
  set("outdoors", "lingjiu");
  set("item_desc", ([
      "jiashan" : "������ɽ����������̫����Ӧ�ÿ��԰ᶯ(move)��.\n",
  ]));
  set("objects",([
      __DIR__"npc/lu" : 1,
      __DIR__"npc/zhang" : 1,
  ]));
//  set("no_clean_up", 0);
  setup();
}

void init()
{
	add_action("do_move", "move");
	add_action("do_enter", "enter");
}

int do_move(string arg)
{      
	object me=this_player();
	if(!arg || arg!="jiashan")
          return notify_fail("��Ҫ�ƶ�ʲô��\n");
	if((int)me->query_str()>28)
		{
		message_vision("$Nʹ�����̵������Ѽ�ɽŲ��,ֻ������¶��һ���󶴣��ƺ����Խ�ȥ(enter)��\n", this_player());
		set("move_jiashan",1);
		}
	else
		message_vision("$Nʹ�����̵�����ҲŲ������ɽ��ֻ���㬵ط����ˡ�\n", this_player());	
	return 1;	
}

int do_enter(object me)
{
	object room;
	object where;
        me=this_player();
	where=environment(me);
	if(!where->query("move_jiashan"))
          return notify_fail("��Ҫ����ȥ��\n");
	if(!( room = find_object(__DIR__"midao1")) )
          room = load_object(__DIR__"midao1");
	message_vision("$N�����ˡ�һ�����������С�\n",me);
        me->move(room);
	set("move_jiashan",0);
        return 1;
}
