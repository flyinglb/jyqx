// hunyuan-yiqi.c ���� ��Ԫһ����
// dts@xkx, cleansword@xkx
inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i, nb, nf, nh, ns;
    nb = (int)me->query_skill("buddhism", 1);
    nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("hunyuan-yiqi", 1);
    ns = (int)me->query("guilty");
        if ( me->query("marry") )
        return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ��Ԫһ������\n");
    if ( me->query("gender") != "����" )
        return notify_fail("���ͯ��֮�壬������ϰ��Ԫһ������\n");
    if ( nb < 100 && nb <= nh )
        return notify_fail("��������ķ���Ϊ�������޷���������Ļ�Ԫһ������\n");
    if ( nf < 10)
        return notify_fail("��Ļ����ڹ���򻹲������޷�����Ԫһ������\n");
    if ( ns > 0 ) 
        return notify_fail("���ŷ�ɮ�����䣬�޷���������Ļ�Ԫһ������\n");
    if (nf <= nh )
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="huntian-qigong") continue;
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="kurong-changong") continue;
        if (sname[i]=="linji-zhuang") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
        if (sname[i]=="jiuyang-shengong") continue;
        if (sname[i]=="taiji-shengong") continue;
        if (sname[i]=="yunlong-shengong") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫһ��������\n");
    }
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("��Ԫһ����ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"hunyuan-yiqi/" + func;
}
