// bibo-shengong.c �̲���
// By Jungu
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("bibo-shengong", 1);
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������ı̲��񹦡�\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    if (me->query_skill("force",1)<20)
        return notify_fail("��Ļ����ڹ���������������ѧ�̲��񹦡�\n");
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="bibo-shengong") continue;
        if (sname[i]=="guiyuan-tunafa") continue;
        if (sname[i]=="hamagong") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�̲��񹦣���\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("�̲���ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"bibo-shengong/" + func;
}
