// necromancy.c ������
// by Java

inherit SKILL;

int valid_learn(object me)
{
    if( (int)me->query_skill("longxiang",1) <
        (int)me->query_skill("necromancy",1) )
      return notify_fail("������������̫���ˣ��޷�����������Ľ�������\n");
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("������ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

