//
// xiaowuxiang.c С���๦
// by secret
// 1997-1-16
//
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i = (int)me->query_skill("xiaowuxiang", 1);
    int t = 1, j;
    for (j = 1; j < i / 10; j++) t*= 2;
    if (((string)me->query("class") != "bonze") && i > 29)
        return notify_fail("�㲻��ɮ�ˣ�ѧ���˸����С���๦��\n");
    if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("��Ļ����ڹ�����㣬����ѧС���๦��\n");
    if ( me->query("gender") == "����" && i > 49)
        return notify_fail("���޸����ԣ����������������������С���๦��\n");
    if (me->query_skill("force",1)<=i)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="huagong-dafa") continue;
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="longxiang") continue;
        if (sname[i]=="shenlong-xinfa") continue;
        if (sname[i]=="xiaowuxiang") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧС���๦��\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("С���๦ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"xiaowuxiang/" + func;
}
