// qufeng.c ����֮��
// By Lgg,1998.9

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("yunv-xinfa", 1) < 10)
                return notify_fail("�����Ů�ķ���򲻹����޷�ѧ����֮����\n");
        if ((int)me->query("max_neili") < 30)
                return notify_fail("�������̫�����޷�ѧϰ����֮����\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("����֮��ֻ�ܿ�ѧϰ����ߡ�\n");
}
