// /u/beyond/mr/skill/shenyuan-gong.c ��Ԫ��
// this is made by beyond
// update 1997.6.23
inherit FORCE;
int valid_enable(string usage)
{
        return usage == "force";
}
int valid_learn(object me)
{

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲������޷������Ԫ����\n");
        if ((int)me->query_skill("murong-xinfa", 1) <= (int)me->query_skill("shenyuan-gong", 1))
                return notify_fail("���Ľ���ķ���Ϊ�������޷������������Ԫ����\n");
        return 1;
}

int practice_skill(object me)
{
       return notify_fail("��Ԫ��ֻ����ѧ(learn)�������������ȡ�\n");
              
}

string exert_function_file(string func)
{
        return __DIR__"shenyuan-gong/" + func;
}

