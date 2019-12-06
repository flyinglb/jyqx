// fangjian3.c
// by shilling 97.2
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��ֻ������ǰ��Ȼһ����һ����װ����Ů��������һ�ѳ�������׼����
�����ţ���������һ���龪֮����ŷ���ԭ��ֻ�Ǹ������ɵ����񣬵�
�ǿ���ȥȴ������һ�����졣�����һ˫����ӨȻ�й⣬��ɷ�����ʱ
ֻ�������Ŀѣ��������ħ��а���۹���Ҳ�벻�����񡣡�����
LONG );
	set("exits", ([
		"east" : __DIR__"tongmen",
	]));
	set("objects",([
		__DIR__"obj/putuan" : 1,
	]));
//	set("no_clean_up", 0);
	set("book_count",1);
	setup();
}

void init()
{
	this_player()->set_temp("ketou_times", 50);
	add_action("do_kneel", "kneel");
	add_action("do_ketou", "ketou");
}

int do_kneel(string arg)
{
      object me;
	me = this_player();
	if ( !arg || arg == "") return 0;
	if ( arg != "putuan") return 0;
	if (!present("putuan",environment(me))) return 0;
	if (me->query_temp("marks/kneel") == 1 )
		return notify_fail("���Ѿ��������ˡ�\n");
	message_vision("$N˫ϥһ��������������\n", me);
	me->add_temp("marks/kneel",1);
	return 1;
}

int do_ketou()
{
	object me, ob;

	me = this_player();
	if ( !me->query_temp("marks/kneel") ) return 0;
	if (!present("putuan",environment(me))) return 0;
	if ( me->query_temp("ketou_times") == 0 )
	{
		message_vision("$N��ͷ̫ƴ���ˡ�\n", me);
		me->set_temp("ketou_times", random(50));
		me->unconcious();
		return 1;
	}

	me->add_temp("ketou_times", -1);	

	message_vision("$N���������ظ������ͷ���ˡ��ˡ��ˡ�������\n", me);

	if ( random(100) == 37 
	&& !present("bojuan", me)
	&& query("book_count") >= 1)
	{
		add("book_count", -1);
		ob=new("/clone/book/bojuan");
		ob->move(me);
message("channel:rumor", HIM"��"+HIR+"ҥ��"+HIM+"��"+HIR+"ĳ�ˣ�"+this_player()->query("name")+"ȡ���˱�ڤ�񹦲�������\n"NOR, users());
		tell_object(me, "ͻȻ���㷢��С�������ϵ�һ�㱡�����Ѳ���Ȼ���ѣ�¶���������\n");
		tell_object(me, "�㼱æ�������˳�����\n");
	}

	return 1;

}

int valid_leave(object me, string dir)
{
	if(me->query_temp("ketou_times") >= 0 ) me->delete_temp("ketou_times");
	if (me->query_temp("marks/kneel") ) me->delete_temp("marks/kneel");
	return ::valid_leave();
}
