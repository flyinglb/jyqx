// duji.c (����)

 inherit SKILL;

 string type() { return "knowledge"; }

 void skill_improved(object me)
 {}

 int valid_learn(object me)
 {
 //      if (!me->query_temp("mark/��") )
 //              return notify_fail("�����ڲ���ѧϰ����д�֡�\n");
         return 1;
 }
