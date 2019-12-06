// Room: /d/snow/herbshop1.c

inherit ROOM;
int do_move(string arg);
int do_climb(string arg);
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��������������ң��ӵ��Ϻ��Ļҳ����ó������������
�˳��룬�����ߵĵ��Ϸ���һ�����ͣ�����һ����������ǽ�ϣ���֪��
��������ʲ���ˣ������ǽ(wall)���ú�ɼľ���ģ�����������Ļ���
ǽ�������Ե���Щ��Ѱ����
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"chuchang",
	]));
	set("item_desc", ([
		"wall" : "һ�°߰������ǽ��\n",
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
        add_action("do_move", "push");
        add_action("do_move", "break");
	add_action("do_climb", "climb");
}

int do_move(string arg)
{
	object paper, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="wall" )
	{
		if (!query("had_staffbook") && me->query("neili",)>200)
		{
			message_vision(
"$N��������������ǽ��ȥ��ֻ������һ���죬ǽ��������һ����ֽ...��\n", this_player());
message("channel:rumor", HIM"��"+HIR+"ҥ��"+HIM+"��"+HIR+"ĳ�ˣ�"+this_player()->query("name")+"�õ��ȷ�ͨ�⣨�ϣ�����\n"NOR, users());
			paper = new("/clone/book/staff_book1");
			paper->move(__FILE__);
			set("had_staffbook", 1);
			return 1;
		}
		message_vision(
"$N�ݺ�һͷײ��ǽ����ǰ��ʱ�ʺ�һƬ...��\n", this_player());
		this_player()->receive_damage("qi",30);
		return 1;
	}
	return 0;
}

int do_climb(string arg)
{
        object me;
        me = this_player();

	if(!arg || arg=="" ) return 0;
	if( arg=="wall" )
	{
		write("����������ǽͷ�����˹�ȥ��\n");
		message("vision",
			me->name() + "��֪������ʲô���أ�����ͻȻ�����ˡ�\n",
			environment(me), ({me}) );
			me->move(__DIR__"wuchang");

	}
}