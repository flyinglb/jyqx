//room: changl15.c
#include <ansi.h>  

inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ������һ������ӱ���
������
LONG );
  set("exits",([
      "west" : __DIR__"changl7",
      "east" : __DIR__"changl8",
      "south" : __DIR__"dating",
      "north" : __DIR__"huayuan",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

void init()
{
        object me = this_player();
     
       if((string)me->query("family/family_name")!="���չ�" && !wizardp(me))
        {
        if(random(10)<=8)
          {
		me->receive_damage("qi",80);
		me->receive_wound("qi",80);
		message_vision(HIR"$N����һ��,...��...,һ���ҽ�!\n"NOR,me);
                me->move(__DIR__"shanjiao");
		tell_object(me,HIR"��Ī������ĵ���ɽ��.\n"NOR);
	  }
	}
}	
