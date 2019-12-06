// Room: /city2/aobai8.c

#include <room.h>
inherit ROOM;

void close_gate();
int do_unlock(string arg);

void create()
{
	set("short", "�η�");
	set("long", @LONG
����һ���谵�ķ��䣬�����������������Ϸ���Ƥ�ޡ�ľ�����̾ߣ���Ȼ
��������˽�����ã���Ѷ�˷������ڡ�һ������������ǽ�ϣ���Ѫ���죬����
���ˡ�
LONG );
	set("objects", ([
		__DIR__"npc/zhuangyu" : 1,
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

    if(!( room = find_object(__DIR__"aobai4")) )
        room = load_object(__DIR__"aobai4");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision","ֻ��ƹ��һ���������Զ������ˡ�\n",
            this_object());
        message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" ,
			this_object());
        room->delete("exits/south");
        message("vision","ֻ��ƹ��һ���������Զ�����������\n", room);
        message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n" ,
			room );
     }
}


int do_unlock(string arg)
{
	object room;
	if (query("exits/north"))
		return notify_fail("�����Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "men"))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision(	"$N������������š�\n", this_player());
	set("exits/north", __DIR__"aobai4");
    if(!( room = find_object(__DIR__"aobai4")) )
        room = load_object(__DIR__"aobai4");
    if(objectp(room))
    {
        set("exits/north", __DIR__"aobai4");
        message_vision("$N��������ţ�ֻ��֨��һ�����ſ��ˡ�\n",this_player());
        room->set("exits/south", __FILE__);
        message("vision","ֻ��֨��һ�������Ŵ�������ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
    }
return 1;
}

