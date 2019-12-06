// Room: /d/xingxiu/shamo2.c

#include <room.h>
inherit ROOM;

void create()
{
       set("short","��ɳĮ");
       set("long", @LONG
����һƬһ���޼ʵĴ�ɳĮ����һ��������ʧ�˷���
����Ҫ�߳����ɳĮ�������¡�
LONG );
	set("outdoors", "xingxiuhai");
        set("no_clean_up", 0);
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"shamo3",
		"south" : __DIR__"shamo4",
		"north" : "/d/npc/m_weapon/lianjianshi",
	]));
	setup();
}

void init()
{
        object ob;
        int water, food;
	ob = this_player();

        water = ob->query("water");
        food = ob->query("food");
        water -= (random(2)+ 1) * water / 20;
        food -= (random(2)+ 1) * food / 20;
        ob->set("water", water);
        ob->set("food", food);
}

int valid_leave(object me, string dir)
{
       if (dir == "west")
          me->add_temp("mark/steps",1);
       if (dir == "east")
          me->add_temp("mark/steps",-1); 
        
	if (me->query_temp("mark/steps") == 10)
         {
     	    me->move("/d/baituo/gebi");
            me->delete_temp("mark/steps");
             return notify_fail("���۵ð���������߳���ɳĮ��\n");
         }  

     if (me->query_temp("mark/steps") == -10)
	    {  
	       me->move("/d/xingxiu/silk4");
           me->delete_temp("mark/steps");
             return notify_fail("���۵ð���������߳���ɳĮ��\n");
     	}
           
        return ::valid_leave(me, dir);
}
