// bahuang-gong.c �˻�����Ψ�Ҷ���
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    if (me->query("gender")!="Ů��" && me->query("family/family_name")!="���չ�")
        return notify_fail("�˻������񹦷����չ����Ӳ���ϰѧ��\n");
    if (me->query_skill("force",1)<=me->query_skill("bahuang-gong",1))
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    if (me->query_skill("force",1)<20)
        return notify_fail("��Ļ����ڹ���������������ѧ�˻�����Ψ�Ҷ��𹦡�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="bahuang-gong") continue;
        if (sname[i]=="yijinjing") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="beiming-shengong") continue;
        if (sname[i]=="huagong-dafa") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�˻�����Ψ�Ҷ��𹦣���\n");
    }
    if (!me->query_skill("bahuang-gong",1)) me->set("learn_bahuang-gong",me->query("mud_age"));
        return 1;
}

int practice_skill(object me)
{
    return notify_fail("�˻�����Ψ�Ҷ���ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"bahuang-gong/" + func;
}
