// buddhism-force
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int lvl = (int)me->query_skill("taiji-shengong", 1);
    int t = 1, i;
    if (lvl<=100)     t=lvl*lvl;
    if ( me->query("gender") == "����" )
        return notify_fail("���޸����ԣ�������������������ղ����񹦡�\n");
    if ((int)me->query_skill("force", 1) < 1000)
        return notify_fail("��Ļ����ڹ���򻹲�����\n");
    if ((int)me->query("unmarried") || (string)me->query("marry") )
	        return notify_fail("ѧ��ղ����񹦱�����ͯ��֮��\n");
	if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="jiuyang-shengong") continue;
        if (sname[i]=="taiji-shengong") continue;
        if (sname[i]=="yijing-force") continue;
		if (sname[i]=="buddhism-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ղ����񹦣���\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("��ղ�����ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"buddhism-force/" + func;
}
