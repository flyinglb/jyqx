// wuzheng-xinfa.c
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
         if (me->query_skill("force", 1) > 9)
                return 1;
        return notify_fail("��Ļ����ڹ�����Ҫ��һ����ߡ�\n");
}

int practice_skill(object me)
{
        return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return SKILL_D("wuzheng-xinfa/") + func;
}

