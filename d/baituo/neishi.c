//ROOM neishi.c

inherit ROOM;
void init();
int do_move(string);
void create()
{
        set("short", "����");
        set("long",
             "���ǡ�ŷ���ˡ������ң��ڲ����������Ȥ���ݽǰ���һ������\n"
         "����������������¶�������(pen) ������һЩ�����������Ǳ���\n"
         "���ȥɹ̫��ʱ���µġ�\n"
        );
        set("exits", ([
                "east" : __DIR__"huayuan",
        ]));
 
        set("no_clean_up", 0);
        set("item_desc", ([
	    "pen" : "���Ǹ����裬�ܽ�ʵ�������ܿ�����\n"
	]));
	setup();
}
void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{

	object me = this_player();
	object room;

	if ((arg != "pen") || !arg)
	  return notify_fail("��Ҫ��ʲô��\n");
	if((int)me->query("str") < 20)
	  return notify_fail("��᲻������\n");
	if(!( room = find_object(__DIR__"midao")) )
	   room = load_object(__DIR__"midao");
	if(!objectp(room))  return notify_fail("ERROR:not found 'midao.c' \n");
	if (!query("exits/down"))
	  {
	  set("exits/down", __DIR__"midao");
	  message_vision("$N�ᶯ�˻��裬ֻ����������¶��һ��������
	      �Ķ��ڡ�\n",me);
	  room->set("exits/up", __FILE__);
	  message("vision", "���洫��һ��ᶯ�����������һ���������˽�����
	  \n", room);
	  }
	 else
	  {
	  delete("exits/down");
	  message_vision("$N�ѻ�������ԭλ�����ڱ���ס�ˡ�\n",me);
	  room->delete("exits/up");
	  message("vision", "���洫��һ��ᶯ��������������ڱ���ס�ˡ�\n", room);
	  }
       return 1;
}
