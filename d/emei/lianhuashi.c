//Room: lianhuashi.c ����ʯ
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","����ʯ");
      set("long",@LONG
��������ʯ���˴���ʯ�����ݺᣬ��������������ܽ�أ��·��������
ϸ������������һ�֣��С������硹���ɴ�������ֱ��ϴ��أ�������ͨ����
������ͨ���϶���
LONG);
      set("objects", ([
           CLASS_D("emei") + "/su" : 1,
           CLASS_D("emei") + "/ling" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "southeast" : __DIR__"jldongkou",
          "eastdown"  : __DIR__"huayanding",
          "westup"    : __DIR__"ztpo1",  
      ]));
//      set("no_clean_up", 0);
      setup();
}
int valid_leave(object me, string dir)
{
      int c_exp,c_skill;
      me = this_player();
      if (dir == "westup" )
      {
         c_exp=me->query("combat_exp");
         c_skill=me->query_skill("dodge",1);
         me->add("qi",-10);
         if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
             me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
         tell_object(me,"������������������һ�󣬺����ˡ�\n");
      }
      return 1;
}

