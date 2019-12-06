// shenlong-xinfa.c 神龙心法

//inherit SKILL;
//void create() { seteuid(getuid()); }
//string type() { return "knowledge"; }
//int practice_skill(object me)
//{   
//    return notify_fail("神龙心法只能靠学(learn)来提高。\n");
//}

inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i, nh;//nb, nf,
//    nb = (int)me->query_skill("shenlong-xinfa", 1);
//    nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("shenlong-xinfa", 1);
    if ( me->query("gender") == "无性" && nh > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的神龙心法。\n");
//    if ( nb < 100 && nb <= nh )
//        return notify_fail("你的云龙心法修为不够，无法领会更高深的神龙心法。\n");
//    if ( nf < 40)
//        return notify_fail("你的基本内功火候还不够，无法领会神龙心法。\n");
//    if (me->query_skill("force",1)<=nh)
//        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="shenlong-xinfa") continue;
        if (sname[i]=="shenyuan-gong") continue;
        if (sname[i]=="wudu-shengong") continue;
        if (sname[i]=="longxiang") continue;
        if (sname[i]=="xiaowuxiang") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
        if (sname[i]=="yunlong-shengong") continue;
        if (sname[i]=="zixia-shengong") continue;
          if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学神龙心法？！\n");
    }
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("神龙内功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"shenlong-xinfa/" + func;
}
