#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
        set("short", "�һ�����");
        set("long",@LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С������в�������
��������������ȥ�ĺá�
LONG );
	set("outdoors", "taohua");
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
    message_vision(HIR"ͻȻһ���һ��������㼲��$N��\n"NOR, this_player());
}

int valid_leave(object me, string dir)
{
        int total_steps;
//        total_steps = ( 100 - (int)this_player()->query_skill("qimen-wuxing",1) ) / 10 ;
//        if ( total_steps <= 0 ) total_steps = 1 ;  
        if( me->query("family/family_name") == "�һ���") total_steps = 1 ; 
           else total_steps = 10;
	if ( dir == "north")
            me->add_temp("taohua/steps",1);
	if ( dir == "south")
            me->add_temp("taohua/steps",-1);

	if (me->query_temp("taohua/steps") == total_steps)
        {
     	    me->move(__DIR__"tao_in");
            me->delete_temp("taohua/steps");
            return notify_fail("�����˰��죬�����߳����һ�����\n");
        }  

        if (me->query_temp("taohua/steps") == - total_steps )
        {  
            me->move(__DIR__"tao_out");
            me->delete_temp("taohua/steps");
            return notify_fail("�����˰��죬�����߳����һ�����\n");
     	}

        return ::valid_leave(me,dir);
}
