inherit SKILL;
string type() { return "knowledge"; }
int valid_enable(string usage) { return usage=="taoism"; }
int valid_learn(object me)
{
    if( (int)me->query_skill("taoism") < 10
    ||  (int)me->query_skill("taoism") <= (int)me->query_skill("qimen-flee") )
        return notify_fail("��ĵ�����Ϊ����������޷�ѧϰ���Ŷ�����\n");
    return 1;
}
string conjure_magic_file(string spell)
{
    return __DIR__ + "qimen-flee/" + spell;
}
