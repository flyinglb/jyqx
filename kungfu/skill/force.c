// force.c
#include <ansi.h>
inherit SKILL;
//int valid_learn() { return 1; }
string exert_function_file(string func)
{
        return "/kungfu/skill/force/" + func;
}
void skill_improved(object me)
{     
        int s;
        s = me->query_skill("force", 1);
    if (s%10==0) {
                tell_object(me, HIW
"�������ڹ������гɣ�������ʸ����ˡ�\n" NOR);
        }
}
