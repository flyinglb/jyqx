// ������
inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i, nb, nf, nh;
    nb = (int)me->query_skill("yunlong-xinfa", 1);
    nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("yunlong-shengong", 1);
    if ( me->query("gender") == "����" && nh > 49)
        return notify_fail("���޸����ԣ���������������������������񹦡�\n");
    if ( nb < 100 && nb <= nh )
        return notify_fail("��������ķ���Ϊ�������޷���������������񹦡�\n");
    if ( nf < 40)
        return notify_fail("��Ļ����ڹ���򻹲������޷���������񹦡�\n");
    if (me->query_skill("force",1)<=nh)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="bingxue-xinfa") continue;
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="shenlong-xinfa") continue;
        if (sname[i]=="yunlong-shengong") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");
    }
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("�����ڹ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"yunlong-shengong/" + func;
}
