// Room: /d/shaolin/zhonglou1.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;

//void close_passage();
//string look_floor();
//int do_open();
//int do_open(string arg);

void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
��������¥�ĵײ㣬һ���������ǽ�ϵĻ�ש��϶��͸��
����������ש����Ͷ�±��µĹ�Ӱ����ͬһ����������ơ���
�Ͽ���������ľ¥�����ƶ��ϣ��ƺ����޾�ͷ��ǽ�ǣ��ݼ���
�൱�ྻ������������ɮ�˴�ɨ��
LONG );
	set("exits", ([
		"up" : __DIR__"zhonglou2",
		"out" : __DIR__"zhonglou",
	]));
//	set("item_desc",([
//		"floor"		:	(: look_floor :),
//	]));
	set("objects",([
		__DIR__"npc/saodi-seng" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
//        object room, me;
        object room;

	if( !arg || arg=="" )
		return 0;

	if( arg=="brick" && !present("blade", this_player()))
		return notify_fail("�����ڣ� ���²��аɣ�\n");

	if( arg=="brick" && !query("exits/down") )
	{
		message_vision( 
		"$N�ߵ�¥���£�ſ�ڵ��ϣ������ý䵶�����ש������������š���\n"
		"�ȵ���שһ�������˳���������¶��һ���󶴣�����ʯ��������ȥ��\n"
		"���������ͨ��һ��������\n", this_player());

		set("exits/down", __DIR__"andao3");
		if( room = find_object(__DIR__"andao3") ) 
		{
			room->set("exits/up", __FILE__);
			message("vision", "�컨���Ȼ����������������¶��һ�����ϵĽ��ݡ�\n",
				room );
		}
		remove_call_out("close_passage");
		call_out("close_passage", 3);
		return 1;
	}
	return 0;
}

void close_passage()
{
	object man, room, *ob;
	int i;

	if( !query("exits/down") )
		return;

	message("vision", 
	"ֻ��ƹ��һ���죬��¥С�ű����˿�����һȺɮ��һӿ���롣\n"
	"�����е���ש���еİ转�����ְ˽ŵ���ש��Ѷ��ڷ���������\n"
	"����ש��佽���պ����֭��\n", this_object() );

	man=new(__DIR__"npc/seng-bing3");
	man->move(this_object());
	man=new(__DIR__"npc/seng-bing3");
	man->move(this_object());
	man=new(__DIR__"npc/seng-bing3");
	man->move(this_object());
	man=new(__DIR__"npc/seng-bing3");
	man->move(this_object());

	ob = all_inventory(this_object());
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || !userp(ob[i]) || ob[i]==man ) continue;
		if( userp(ob[i]) ) { 
			man->set_leader(ob[i]);
			man->kill_ob(ob[i]);
			ob[i]->fight_ob(man);
		}
	}

	if( room = find_object(__DIR__"andao3") ) {
//		room->delete("exits/up");
		message("vision", 
	"ֻ��ƹ���Ҽ������죬���ż��ι��̵���ˮ����������\n"
	"���ϵĶ��ڱ�����ש������ʵʵ�ط���������\n", room );
	}
	delete("exits/down");
}

string look_floor()
{
	return
	"һƬ��ʵƽ������ש���棬ֻ��¥���µ�һ�Ǵ����԰�͹��ƽ��\n";
}
*/
