// hunyuan-yiqi.c 少林 混元一气功
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
        return notify_fail("你已经破了色戒，无法再学习混元一气功！\n");
    if ( me->query("gender") != "男性" )
        return notify_fail("你非童男之体，不能练习混元一气功。\n");
    if ( nb < 100 && nb <= nh )
        return notify_fail("你的禅宗心法修为不够，无法领会更高深的混元一气功。\n");
    if ( nf < 10)
        return notify_fail("你的基本内功火候还不够，无法领会混元一气功。\n");
    if ( ns > 0 ) 
        return notify_fail("你屡犯僧家数戒，无法领会更高深的混元一气功。\n");
    if (nf <= nh )
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
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
        return notify_fail("你不先散了别派内功，怎能学混元一气功？！\n");
    }
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("混元一气功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"hunyuan-yiqi/" + func;
}
