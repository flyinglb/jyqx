// jiuyang-shengong.c ��ľ��
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
    int lvl = (int)me->query_skill("kumu-shengong", 1);
                    
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������Ŀ�ľ�񹦡�\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("��Ļ����ڹ���򻹲������޷�����ľ�񹦡�\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�����������ʵ����ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ľ�񹦣���\n");
    }
    return 1;
}
string exert_function_file(string func)
{
    return __DIR__"kumu-shengong/" + func;
}
int practice_skill(object me)
{
        return notify_fail("��ľ��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
