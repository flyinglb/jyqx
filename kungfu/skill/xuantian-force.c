// �����޼��ڹ�
inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i, nf, nh;
    nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("xuantian-force", 1);
    if ( me->query("gender") == "����" && nh > 49)
        return notify_fail("���޸����ԣ���������������������������޼��ڹ���\n");
    if ( nf < 20)
        return notify_fail("��Ļ����ڹ���򻹲������޷���������޼��ڹ���\n");
    if (me->query_skill("force",1)<=nh)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="bingxue-xinfa") continue;
        if (sname[i]=="xuantian-force") continue;
        if (sname[i]=="wudu-shengong") continue;
        if (sname[i]=="zixia-shengong") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����޼��ڹ�����\n");
    }
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("�����޼��ڹ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"xuantian-force/" + func;
}
