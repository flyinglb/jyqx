// huagong-dafa.c ������
// By yucao
// Modified by cleansword
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i = (int)me->query_skill("huagong-dafa", 1);
    int t = 1, j;
    if(i <= 100)
        for (j = 1; j < i / 10; j++)
            t*= 2;
    if ( me->query("gender") == "����" && i > 49)
        return notify_fail("���޸����ԣ���������������������Ļ����󷨡�\n");
    if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("��Ļ����ڹ�����㣬����ѧ�����󷨡�\n");
    if(i<=100)
    {
        if (i > 10 && -(int)me->query("shen") < t * 60) 
            return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
    }
    else
    {
        if (-(int)me->query("shen") < (51200 + (i - 100) * 500)) 
            return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
    }
    if (me->query_skill("force",1)<i)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="bahuang-gong") continue;
        if (sname[i]=="huagong-dafa") continue;
        if (sname[i]=="longxiang") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="xiaowuxiang") continue;
        if (sname[i]=="yijinjing") continue;
        if (sname[i]=="yunv-xinfa") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����󷨣���\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"huagong-dafa/" + func;
}
