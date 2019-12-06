#include <room.h>
inherit ROOM;

void close_gate();
int do_unlock(string arg);

void create()
{
	set("short", "�����鷿");
	set("long", @LONG
�����������鷿��ȴû��һ���顣���ֹ���������Ŀ��������ͭ������
���������ʣ����鱦ʯ��Ӧ�о��У�ֻҪӵ��һ�����͹����һ�����ˡ���
��ǽ����һ��������������һ���顣
LONG );
	set("item_desc", ([
		"picture" : "\n���Ż���һ�㣬��֪Ϊʲô���������\n",
		"book" : "\n������Ǳ�����ׯ�ʳǼ��������ġ���ʷ���ԡ���\n",
	]));
	set("exits", ([
		"south" : __DIR__"aobai4",
	]));
	set("objects", ([
		"/d/city2/obj/picture" : 1,
		"/d/city2/obj/bookming" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_unlock", "unlock");
	add_action("do_unlock", "open");
}

void close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"aobai9")) )
        room = load_object(__DIR__"aobai9");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision","ֻ��ƹ��һ���������Զ������ˡ�\n",
            this_object());
        message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n" ,
			this_object());
        room->delete("exits/south");
        message("vision","ֻ��ƹ��һ���������Զ�����������\n", room);
        message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" ,
			room );
     }
}


int do_unlock(string arg)
{
	object ob,room;
	if (query("exits/north"))
		return notify_fail("�����Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "door"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("anmenkey", this_player())))
		return notify_fail("�㲻��������\n");
	message_vision(
	"$N��һ��Կ�״������ţ�����Կ��ȴ����.\n", this_player());
	destruct(ob);
	if (this_player()->query_temp("doorisok"))        
        {
	set("exits/north", __DIR__"aobai9");
	if(!( room = find_object(__DIR__"aobai9")) )
        room = load_object(__DIR__"aobai9");
	if(objectp(room))
    	{
        set("exits/north", __DIR__"aobai9");
        message_vision("$N��������ţ�ֻ��֨��һ�����ſ��ˡ�\n",this_player());
        room->set("exits/south", __FILE__);
        message("vision","ֻ��֨��һ�������Ŵ�������ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
    	}
        this_player()->set_temp("doorisok",0);
        } 
	return 1;
}

