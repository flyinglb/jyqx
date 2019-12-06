//Room: leidongping.c �׶�ƺ
//Date: Oct. 2 1997 by That
#include <ansi.h>
inherit ROOM;

void create()
{
      set("short","�׶�ƺ");
      set("long",@LONG
�׶�ƺһ������·���պ��ˣ�·���Ǳ����������ɼ�֣�·���������
�ľ���Ͽ�ȡ����ﳤ���������֣����ɺڰ������Ͻ��������Ա���һ������
�ɴ������ǡ���ʮ���̡�����������µ�ϴ��ء�
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"lingyunti",
          "southup"    : __DIR__"bashisipan1",
          "east"       : __DIR__"lengsl1",
      ]));
      set("no_clean_up", 0);
      setup();
}

void init()
{
   add_action("do_say","say");
}
int do_say()
{
      object me;
      int qi_cost,c_exp,c_skill;
      me = this_player();
      c_exp=me->query("combat_exp");
      c_skill=me->query_skill("force",1);
      qi_cost = 10;

      if (me->query("qi")>qi_cost) 
      {
message_vision(CYN"$N��˵��һ���֣�ɲ�Ǽ侪��Ѹ�磬�������������걩����\n"NOR, me);
         if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
              me->improve_skill("force", (int)me->query_skill("force", 1));
           me->receive_damage("qi", qi_cost );
      }
      else
      {
       message_vision(CYN"$N��˵��һ���֣�ɲ�Ǽ侪��Ѹ�磬�������������걩����
$Nһ���ӱ����У�ȫ���顣\n"NOR, me);
      }
      return 1;
}

int valid_leave(object me, string dir)
{
      int c_exp,c_skill;
      me = this_player();
      if (dir == "southup" )
      {
         c_exp=me->query("combat_exp");
         c_skill=me->query_skill("dodge",1);
         me->add("qi",-10);
         if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_exp< 101))
             me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
         tell_object(me,"�����ϰ�ʮ���̣���Щ���ˡ�\n");
      }
      return 1;
}

