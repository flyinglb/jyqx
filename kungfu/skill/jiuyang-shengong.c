// jiuyang-shengong.c 九阳神功
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
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。\n");
//  if ( me->query("gender") != "男性")
//      return notify_fail("九阳神功需要阳刚之气，不适合你学。\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("你的基本内功火候还不够，无法领会九阳神功。\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
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
        return notify_fail("你不先散了别派内功，怎能学九阳神功？！\n");
    }
    return 1;
}
string exert_function_file(string func)
{
    return __DIR__"jiuyang-shengong/" + func;
}
int practice_skill(object me)
{
        return notify_fail("九阳神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}
