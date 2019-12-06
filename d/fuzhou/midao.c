// room: midao.c
//Jay 4/7/96

#include <room.h>

inherit ROOM;
int do_press(string arg);

void create()
{ 
       set("short", "�ܵ�");
       set("long", @TEXT
����ˮ�����һ���ܵ�����Χ����Щ���أ�ֻ�г��ں����������
ʪ������ǽ�������Ŀ�ʯ�壬�ֱ���ţ����������������Ա߻���һ��
����(tieban)���ڵ��ϡ�
TEXT );
        set("exits", ([
            "out" : __DIR__"well",
        ]));

        set("item_desc", ([
            "tieban" :      
            "��������бб��д�ţ������ǵ���һ�Σ������㬶��顣\n",
        ]) );
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_press", "press");
}

int do_press(string arg)
{
	string p;

	p = sprintf("%d", this_player()->query("passwd"));
	if( !arg || arg == "" )
	{
		write("��Ϲ����\n");
		return 1;
	}
	if( arg == p )
	{
		message_vision("ֻ����һ��¡¡��������Զ������\n", this_player());
		message_vision("ʯ�建�����˿�����¶��һ������\n", this_player());
		set("exits/enter", __DIR__"mishi");
		write("\n\nһ�����������㣺��ס������룬�Ժ���Ϳ��������������ˣ�\n\n");

		remove_call_out("close");
		call_out("close", 5, this_object());

		return 1;
	}
	else
	{
		write("�����룺���챣����������ţ�\n");
		if (random(10) != 8)
		{
			message_vision("$Nһ���Ұ���ʲô��ӦҲû�С�\n", this_player());
			return 1;
		}
		else
		{
			message_vision("$Nһ���Ұ���ͻȻʯ��ķ�϶�����һ֧��������\n", this_player());
			this_player()->die();
			return 1;
		}
	}
}

void close(object room)
{
        message("vision","��¡¡���������֮��ʯ���ֺ����ˡ�\n", room);
        room->delete("exits/enter");
}
