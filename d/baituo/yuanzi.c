// yuanzi.c

inherit ROOM;

void init();
string look_gate();
int do_open(string);
int do_lock(string);
void do_close(object room);

void create()
{
        set("short", "Ժ��");
        set("long",
             "����һ����Ժ�ӣ���ɨ��һ����Ⱦ������װ����������񣬴���\n"
         "���¡������������⡣������һ�䴢���ң�����(door)�ر��š�����\n"
         "�ǡ�����ɽׯ���Ĵ������ϱ߾��Ǵ����ˡ�\n"
        );

        set("exits", ([
                "northup" : __DIR__"dating",
                "west" : __DIR__"wuqiku",
                "south" : __DIR__"damen",
        ]));

        set("outdoors", "baituo");
        set("no_clean_up", 0);

        set("item_desc", ([
            "door" : (: look_gate :),
        ]));

        set_temp("lock",1);

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_lock", "lock");

}

string look_gate()
{
	if (query_temp("lock") == 0)
		return "���ϵ����������ˡ�\n";
	return "�����ű�����������ס��\n";
}

int do_open(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="door")
		return notify_fail("��Ҫ��ʲô��\n");

	if( query_temp("lock") == 1 && !present("key", me) )
		return notify_fail("Կ�׶�û�У���ô���ţ�\n");

	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");

	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N��Կ�ײ�����ף�ֻ��������ડ�һ���������ˡ�\n", me);
		message("vision", "���洫��һ������������ֻ��������ડ�һ���������ˡ�
  \n",room);
}
        room->set("exits/out", __FILE__);
        set("exits/enter", __DIR__"storeroom");
        call_out("do_close", 3, room);
/*
   message_vision("$N�����ƿ��ţ����˽�ȥ�����ְ�������������\n",me);
   message("vision", "�������˽��������ְ��������ˡ�\n",room);
   me->move(room);
*/
   return 1;
}

void do_close(object room)
{
        tell_room(this_object(),"һ���紵������ž��һ�������ˡ�\n");
        tell_room(room,"һ���紵������ž��һ�������ˡ�\n");
        delete("exits/enter");
        room->delete("exits/out");
}

int do_lock(string arg)
{
	object me=this_player();
	object room;

	if(!arg ||  arg!="door")
		return notify_fail("��Ҫ��ʲô��\n");
	if( !present("key",me))
		return notify_fail("Կ�׶�û�У���ô���ţ�\n");
	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");

	if(query_temp("lock") == 1)
		return notify_fail("���Ѿ������ˡ�\n");
	set_temp("lock",1);
	message_vision("$N��Կ�ײ�����ף�ֻ��������ડ�һ�����������ϡ�\n",me);
	message("vision", "���洫��һ����������������ֻ��������ડ�һ�������������ˡ�
  \n",room);

	return 1;
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "����ɽ��") && dir == "west")
           return notify_fail("�˴��˱��ɽ��أ���ֹ����\n");

        return ::valid_leave(me, dir);
}
