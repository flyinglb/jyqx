// taiji-shengong.c 太极神功
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
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");
    if ( me->query("class") == "bonze" )
        return notify_fail("太极神功讲究阴阳调合，有违佛家六根清净之意，"
            +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");
    if ( me->query_skill("buddhism",1) )
        return notify_fail("自古佛道两家不相容，你练了秃驴们的心法，还学太极神功做什麽！\n");
    if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("你的基本内功火候还不够。\n");
    if(lvl<=100)
    {
        if (lvl > 10 && (int)me->query("shen") < t * 20) 
            return notify_fail("你的侠义正气太低了。\n");
    }
    else
    {
        if ((int)me->query("shen") < (51200 + (lvl - 100) * 2000)) 
            return notify_fail("你的侠义正气太低了。\n");
    }
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
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
            return notify_fail("你不先散了别派内功，怎能学太极神功？！\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"taiji-shengong/" + func;
}
