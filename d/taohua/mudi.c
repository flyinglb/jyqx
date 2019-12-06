#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Ĺ��");
	set("long", @LONG
�������һ����������˵�Ĺ�ء�Ĺ����Χ����һЩ�����Ļ���������
�İ׻����ǵ�㡣�׻��м���һ�ߴ��ʯ�� (bei)�����������ȼ�̵�ʯ
�š�����Ĺ�ظɸɾ�������Ȼ�������˴�ɨ��
LONG );
	set("outdoors", "taohua");
	set("exits", ([
            "south" : __DIR__"road3",
	]));
	set("item_desc", ([
            "bei": "������ţ��һ���Ů����������֮Ĺ��\n"
	]) );
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_push", "push");
}
void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==3
        &&  (int)query("right_trigger")==3
	&&	!query("exits/down") ) {
        message("vision", "Ĺ�ź�Ȼ���������������������������ƶ�����¶��һ�����µĽ��ݡ�\n",
			this_object() );
        set("exits/down", __DIR__"mudao");
        if( room = find_object(__DIR__"mudao") ) {
			room->set("exits/up", __FILE__);
            message("vision", "Ĺ�ź�Ȼ���������������������������ƶ�����¶��һ�����ϵĽ��ݡ�\n",
				room );
		}
		delete("left_trigger");
		delete("right_trigger");
		call_out("close_passage", 30);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
    message("vision", "Ĺ�ź�Ȼ����������������������£�������µ�ͨ����ס�ˡ�\n",
		this_object() );
    if( room = find_object(__DIR__"mudao") ) {
		room->delete("exits/up");
        message("vision", "Ĺ�ź�Ȼ����������������������£�������ϵ�ͨ����ס�ˡ�\n"
                        HIR "���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" NOR ,
			room );
	}
	delete("exits/down");
}

int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="bei" ) {
		write("�������ƶ�Ĺ�������������������ƶ�....\n");
		return 1;
	}
	if( this_player()->query("neili") <100) {
		write("�������ƶ�Ĺ������������̫��....\n");
		return 1;
	}
	if( sscanf(arg, "bei %s", dir)==1 ) {
		if( dir=="right" ) {
			message_vision("$N��Ĺ��������...����Ȼ��������Ĺ�����ƻ�ԭλ��\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N��Ĺ��������...����Ȼ��������Ĺ�����ƻ�ԭλ��\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("��Ҫ��Ĺ�������Ǹ�����\n");
			return 1;
		}
	}
}
void reset()
{
	::reset();
	delete("left_trigger");
	delete("right_trigger");
}
