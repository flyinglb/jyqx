//Room: jiejianyan.c �⽣��
//Date: Sep 22 1997

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short","�⽣��");
      set("long",@LONG
���������м���ʢ�����䵱�⽣�ң����½⽣��ˮ�������ˡ�����
��ʿ���˶��Ծ��⽣����ʾ���䵱�ɵ��𾴡�ǧ���������������⡣
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/shan": 1,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"slxl2",
          "westup"    : __DIR__"slxl3",
      ]));
//      set("no_clean_up", 0);
      setup();
}

int valid_leave(object me, string dir)
{

        me = this_player();
        if ((me->query_temp("weapon") || me->query_temp("secondary_weapon"))
             && dir == "westup"
             && objectp(present("zhang cuishan", environment(me))))
        {
            message_vision(CYN"�Ŵ�ɽ��������ɫ�˵ȣ����⽣�Ҷ���⽣��ǧ�������������⣡��$N�����䵱ɽ�棬����Ӳ����ֻ������һ����\n\n\n"NOR,me);
            me->move("/d/wudang/slxl2");
            return notify_fail(RED"�벻Ҫװ��������\n"NOR);
         }
         return ::valid_leave(me, dir);
}
