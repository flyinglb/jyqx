// duji.c (毒技)

 inherit SKILL;

 string type() { return "knowledge"; }

 void skill_improved(object me)
 {}

 int valid_learn(object me)
 {
 //      if (!me->query_temp("mark/朱") )
 //              return notify_fail("你现在不能学习读书写字。\n");
         return 1;
 }
