#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
        set("short", "��ľ�����");
        set("long",@LONG
����ǰ��Ȼһ���������У�ֻ������ǰ�󣬵�����������ǵ�
�Ĳ�֪���ľ����������ɰأ�������ɼ������һ����ʵ��֦Ҷ��
һ�����ɡ��������գ�������ա����ƺ���ʧ�˷�����ûͷ��
Ӭ�㵽���Ҵ���
LONG );
	set("exits", ([
		"east" :  __FILE__,
		"west" :  __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
	]));             
	set("no_clean_up", 0);
        setup();
}
void init()
{
    this_player()->receive_damage("qi", 15);
    this_player()->receive_wound("qi",  15);
    message_vision(HIG"ͻȻһ���ľ׮��������������$N��\n"NOR, this_player());
}

int valid_leave(object me, string dir)
{
        int total_steps ;
        mapping myfam;
        total_steps = 10 ;
        if ( total_steps <= 0 ) total_steps = 1 ;  
        myfam = (mapping) this_player()->query("family");
        if(myfam && myfam["family_name"] == "����") total_steps = 1 ; 
	if ( dir == "west")
            me->add_temp("mingjiao/steps",1);
	if ( dir == "east")
            me->add_temp("mingjiao/steps",-1);

	if (me->query_temp("mingjiao/steps") == total_steps)
        {
     	    me->move(__DIR__"jmqshenmu");
            me->delete_temp("mingjiao/steps");
                return notify_fail("�����˰��죬�����ߵ���ľ������! \n");
        }  

        if (me->query_temp("mingjiao/steps") == - total_steps )
        {  
	     me->move(__DIR__"jmqshulin6");
             me->delete_temp("mingjiao/steps");
             return notify_fail("�����˰��죬�����߳��˾�ľ����ء�\n");
     	}

        return ::valid_leave(me,dir);
}
