// tianjing.c
inherit ROOM;

void create()
{
        set("short", "���쾮");
        set("long", @LONG
���߹�һ�����쾮���쾮���Ҹ�ֲһ����÷��֦�����������ǲ�
����������÷ׯ���ţ������Ǵ�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"dating",
        ]));
        set("objects", ([ /* sizeof() == 2 */
            __DIR__"npc/huyuan" : 1,
        ]));
        set("outdoors", "meizhuang");
//        set("no_clean_up", 0);

        setup();
//        replace_program(ROOM);
}
void init()
{
        add_action("do_open", "open");
}
int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"gate")) )
		room = load_object(__DIR__"gate");
	if(objectp(room))
	{
		set("exits/south", __DIR__"gate");
		message_vision("$Nʹ���Ѵ��Ŵ��˿�����\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"gate")) )
		room = load_object(__DIR__"gate");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "��Ժ��ǰ�Ѵ��Ź���������\n", this_object());
		room->delete("exits/north");
		message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", room);
	}
}

