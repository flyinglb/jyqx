// huntian-qigong.c 混天气功
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i = (int)me->query_skill("huntian-qigong", 1);
    int t = 1, j;
    for (j = 1; j < i / 10; j++) t*= 2;
    if ( me->query("gender") == "无性" && i > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的混天气功。\n");
    if (i > 10 && ((int)me->query("shen") > t * 100 ||
            (int)me->query("shen") < t * (-100)))
        return notify_fail("学混天气功，要不正不邪、亦正亦邪，你可做得不够呀！\n");
    if (me->query_skill("force",1)<=i)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="bingxue-xinfa") continue;
        if (sname[i]=="huntian-qigong") continue;
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="linji-zhuang") continue;
        if (sname[i]=="jiuyang-shengong") continue;
        if (sname[i]=="shenlong-xianfa") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="yijinjing") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学混天气功？！\n");
    }
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("混天气功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"huntian-qigong/" + func;
}
