// /u/beyond/mr/fenmu.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIB"�س�"NOR);
        set("long", @LONG
������Ľ���ϵķس�, Ľ��������Ҫ����������,��������, 
��һ���⡣ÿ������ʱ��, Ľ�ݺ��ᶼҪ��������档����һ����
�ظ�������סĿ, ����Ľ�ݸ�֮��Ľ�ݲ�֮Ĺ��
LONG);
        set("exits", ([
                "west" : __DIR__"xiaojing1-4",
        ]));

        set("book_count",1);
        
        setup();
}

void init()
{
	if (!this_player()->query_temp("ketou_times"))
	        this_player()->set_temp("ketou_times",
			1+random(this_player()->query_skill("force", 1)));
        add_action("do_ketou", "ketou");
}

int do_ketou()
{
        object me, ob;

        me = this_player();
                
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

        if ( me->query_temp("ketou_times") == 0 )
        {
                message_vision("$N��ͷ�ĵ����˹�ȥ��\n", me);
                me->set_temp("ketou_times",
			1+random(me->query_skill("force", 1)));
                me->unconcious();
                return 1;
        }

        me->add_temp("ketou_times", -1);        

        message_vision("$N�ϵع���������Ĺ����ǰ��ͷ��\n", me);

 if ( random (30) == 10 
        && !present("force book", me)
        && query("book_count") >= 1)
        {
                add("book_count", -1);
 ob=new(__DIR__"obj/neigong-book");
  ob->move(this_object());
                tell_object(me, "ͻȻ����ǰ��ž��һ������һ���ڹ��ķ���\n");
        }

        if ( (int)me->query("jing")<0) {
                 write("��̫���ˣ�Ъ���ٿ�ͷ�ɣ�\n");              
       		 return 1;
	}
        if ((int)me->query_skill("force", 1) >= 30 
        && (int)me->query_skill("force", 1) <= 100 
        && present("force book", me) )
        {        
                me->receive_damage("jing", 20);
                me->improve_skill("force", me->query("int"));
                if ( random(5) == 0 )
tell_object(me, "ڤڤ֮�У����ƺ����ý���������ڹ���������ѡ�\n");
        }

        return 1;
}

