// taiji-shengong.c ̫����
// By Xiang
// Modified by Hop
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int lvl = (int)me->query_skill("taiji-shengong", 1);
    int t = 1, i;
    if (lvl<=100)     t=lvl*lvl;
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ����������������������̫���񹦡�\n");
    if ( me->query("class") == "bonze" )
        return notify_fail("̫���񹦽����������ϣ���Υ��������徻֮�⣬"
            +RANK_D->query_respect(me)+"���޴˹������������\n");
    if ( me->query_skill("buddhism",1) )
        return notify_fail("�Թŷ�����Ҳ����ݣ�������ͺ¿�ǵ��ķ�����ѧ̫������ʲ�ᣡ\n");
    if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("��Ļ����ڹ���򻹲�����\n");
    if(lvl<=100)
    {
        if (lvl > 10 && (int)me->query("shen") < t * 20) 
            return notify_fail("�����������̫���ˡ�\n");
    }
    else
    {
        if ((int)me->query("shen") < (51200 + (lvl - 100) * 2000)) 
            return notify_fail("�����������̫���ˡ�\n");
    }
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="jiuyang-shengong") continue;
        if (sname[i]=="taiji-shengong") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="wudu-shengong") continue;
        if (sname[i]=="yijinjing") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ̫���񹦣���\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("̫����ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"taiji-shengong/" + func;
}
