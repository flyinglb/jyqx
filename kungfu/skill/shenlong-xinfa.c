// shenlong-xinfa.c �����ķ�

//inherit SKILL;
//void create() { seteuid(getuid()); }
//string type() { return "knowledge"; }
//int practice_skill(object me)
//{   
//    return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
//}

inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i, nh;//nb, nf,
//    nb = (int)me->query_skill("shenlong-xinfa", 1);
//    nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("shenlong-xinfa", 1);
    if ( me->query("gender") == "����" && nh > 49)
        return notify_fail("���޸����ԣ���������������������������ķ���\n");
//    if ( nb < 100 && nb <= nh )
//        return notify_fail("��������ķ���Ϊ�������޷���������������ķ���\n");
//    if ( nf < 40)
//        return notify_fail("��Ļ����ڹ���򻹲������޷���������ķ���\n");
//    if (me->query_skill("force",1)<=nh)
//        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="shenlong-xinfa") continue;
        if (sname[i]=="shenyuan-gong") continue;
        if (sname[i]=="wudu-shengong") continue;
        if (sname[i]=="longxiang") continue;
        if (sname[i]=="xiaowuxiang") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
        if (sname[i]=="yunlong-shengong") continue;
        if (sname[i]=="zixia-shengong") continue;
          if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����ķ�����\n");
    }
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("�����ڹ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"shenlong-xinfa/" + func;
}
