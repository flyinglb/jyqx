//Room: hcaxiuxishi.c ��������Ϣ��
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","��������Ϣ��");
      set("long",@LONG
�����Ƕ��һ����ֵ���Ϣ�ҡ���������������������������˺ܶ�ľ����
�м���ҹ�����ֵ�Сʦ̫����˯����
������Ϣ�������������
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north" : __DIR__"hcachanfang", 
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
void init()
{
//      add_action("do_jingzuo", "jingzuo");
}

int do_jingzuo()
{
      mapping myfam;
      object me;
      int jing_cost,qi_cost,skillslvl;

      me = this_player();
      myfam = (mapping)me->query("family");
      skillslvl = (int) me->query_skill("mahayana",1);

      if (me->is_busy()) return 0;
      if ((skillslvl<10) || !myfam || (myfam["family_name"] != "������"))
         return 0;
      jing_cost = 600 / (int)me->query("int");
      qi_cost = 500 / (int)me->query("int");

      me->receive_damage("jing", jing_cost );
      me->receive_damage("qi", qi_cost );
      if (random((int)100/skillslvl)==0)
      {
           me->add("potential",1);
           me->add("combat_exp",1);
      }
      write("�����꣬�������ƣ�͡���Ϣһ�°ɣ�\n");
      me->start_busy(3);
      return 1;
}
