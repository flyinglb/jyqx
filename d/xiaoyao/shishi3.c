// shishi3.c
// by shilling 97.2

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������һ�������ʯ�ң���֮������κ�һ������������������һ����
��������ľ�Ƴɵ����(shelf),���������ȴ�յ�������һ����Ҳû�У���
����ʱ��ֻ������������ˡ������ɡ����������ɡ���������ɡ�֮�����
Ŀ�����������У����Ǹ��Ÿ��ɵ��书�ؼ������л���һ��С��(bed)��
LONG );
	set("exits", ([
		"south" : __DIR__"shidong",
	]));
	set("item_desc", ([
		"bed"   : "һ�źܼ�ª��С����\n",
		"shelf" : "���������һ��С�����������֮����������֮�磬�����������Ϊ��ң����\n",
	]));
	set("book1_count",1);
	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_strike","strike");
        add_action("do_move","move");
}

int do_strike(string arg)
{
        object me;

        me=this_player();
        if(!arg || arg!="shelf") return 0;
        message_vision("$N���ſ��ţ���Ȼ�͵�һ������ܴ�ȥ�������ܡ������������������˼�����\n",me);
	if ( random(100) > 94)
	{
message_vision("��Ȼ��$N����һ�������ٺٵؼ�Ц�����������ϵ�������\n",me);
message_vision("���ţ���֪���������һ֧������������$N��\n",me);
		me->die();
	}
        if (random(100)==50 && !present("miji1",me) && !present("blade_book2",me) && query("book1_count")>=1)
	{
     		add("book1_count", -1);
		me=new("/clone/book/blade_book2");
		me->move(__DIR__"shishi3");
message("channel:rumor", HIM"��"+HIR+"ҥ��"+HIM+"��"+HIR+"ĳ�ˣ�"+this_player()->query("name")+"�õ��˵�����������\n"NOR, users());
		tell_object(me, "ͻȻž��һ������һ������������ϵ���������\n");
	}
        return 1; 
}

int do_move(string arg)
{
	object me;

	me=this_player();
	if(!arg || arg!="bed") return 0;
	message_vision("$N������С���ƿ����������澹Ȼ��һ������ͨ����\n",me);
	me->move(__DIR__"midao1");
	tell_object(me,"������һ���¡¡���������㶨��һ�����Լ��Ѿ�����������ͨ�����ˡ�\n");
	return 1; 
}
