// jiuyang-shengong.c ������
// cleansword
inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("jiuyang-shengong", 1);
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");
//  if ( me->query("gender") != "����")
//      return notify_fail("��������Ҫ����֮�������ʺ���ѧ��\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="huntian-qigong") continue;
        if (sname[i]=="linji-zhuang") continue;
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
        if (sname[i]=="jiuyang-shengong") continue;
        if (sname[i]=="taiji-shengong") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");
    }
    return 1;
}
string exert_function_file(string func)
{
    return __DIR__"jiuyang-shengong/" + func;
}
int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
