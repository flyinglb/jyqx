// huntian-qigong.c ��������
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i = (int)me->query_skill("huntian-qigong", 1);
    int t = 1, j;
    for (j = 1; j < i / 10; j++) t*= 2;
    if ( me->query("gender") == "����" && i > 49)
        return notify_fail("���޸����ԣ���������������������Ļ���������\n");
    if (i > 10 && ((int)me->query("shen") > t * 100 ||
            (int)me->query("shen") < t * (-100)))
        return notify_fail("ѧ����������Ҫ������а��������а��������ò���ѽ��\n");
    if (me->query_skill("force",1)<=i)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="bingxue-xinfa") continue;
        if (sname[i]=="huntian-qigong") continue;
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="linji-zhuang") continue;
        if (sname[i]=="jiuyang-shengong") continue;
        if (sname[i]=="shenlong-xianfa") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ������������\n");
    }
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
        return __DIR__"huntian-qigong/" + func;
}
