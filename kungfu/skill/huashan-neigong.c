inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i = (int)me->query_skill("huashan-neigong", 1);
    int t = 1, j;
    if(i <= 100)
        for (j = 1; j < i / 10; j++)
            t *= 2;
    if ( me->query("gender") == "����" && i > 49)
        return notify_fail("���޸����ԣ���������������������Ļ�ɽ�ڹ���\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="huashan-neigong") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
        if (sname[i]=="zixia-shengong") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ϼ�񹦣���\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("��ɽ�ڹ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
        return __DIR__"huashan-neigong/" + func;
}
