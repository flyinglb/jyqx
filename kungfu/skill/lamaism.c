// lamaism.c �����ķ�

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
    if( (int)me->query_skill("taoism",1) > 1 )
      return notify_fail("��ѧ��ţ���ӵ��ķ����޷����������ķ���\n");
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

