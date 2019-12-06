// Room: /u/zqb/tiezhang/xxs.c
#include <room.h>
inherit ROOM;
void init();
int do_open();
int do_close();
void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
    ����һ���ڰ��Ĵ󷿼䡣�����ú���������ס����¶˿������  
�����������������ʮ����ľ���ɵĴ��̣�������������İ��ڼ�ʱ�õ� 
��Ϣ�����ﾲ���ĵģ��ڰ���ż��������΢��������
LONG	);
    set("sleep_room", 1);
    set("no_fight", 1);
	
   
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_tui", "tui");
       add_action("do_tui", "push");
}
void close_men()
{
	object room;

	if(!( room = find_object(__DIR__"zoulang-4")) )
		room = load_object(__DIR__"zoulang-4");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", this_object());
		room->delete("exits/north");
		message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
	}
}
int do_tui(string arg)
{
	object room;
	object me = this_player();

	if (query("exits/south"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (arg != "men" && arg != "door" && arg != "south")
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"zoulang-4")) )
		room = load_object(__DIR__"zoulang-4");
	if(objectp(room))
	{
		set("exits/south", __DIR__"zoulang-4");
		message_vision("$N������ŵذ��Ŵ򿪡�\n", this_player());
		room->set("exits/north", __FILE__);
		
		if (me->query_temp("sleeped"))
		{
		message("vision", "֨��һ����"+me->query("name")+"��������Ŵ��ˡ�\n",
		room);
		} else 
		{
		message("vision", "֨��һ����"+me->query("name")+"��������Ŵ򿪡�\n",
			 room);
		}	
		
		remove_call_out("close_men");
		call_out("close_men", 10);
	}

	return 1;
}

