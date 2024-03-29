// bahuang-gong.c 八荒六合唯我独尊功
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    if (me->query("gender")!="女性" && me->query("family/family_name")!="灵鹫宫")
        return notify_fail("八荒六合神功非灵鹫宫弟子不能习学！\n");
    if (me->query_skill("force",1)<=me->query_skill("bahuang-gong",1))
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    if (me->query_skill("force",1)<20)
        return notify_fail("你的基本内功基础不够，怎能学八荒六合唯我独尊功。\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="bahuang-gong") continue;
        if (sname[i]=="yijinjing") continue;
        if (sname[i]=="taixuan-gong") continue;
        if (sname[i]=="beiming-shengong") continue;
        if (sname[i]=="huagong-dafa") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
                return notify_fail("你不先散了别派内功，怎能学八荒六合唯我独尊功？！\n");
    }
    if (!me->query_skill("bahuang-gong",1)) me->set("learn_bahuang-gong",me->query("mud_age"));
        return 1;
}

int practice_skill(object me)
{
    return notify_fail("八荒六合唯我独尊功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"bahuang-gong/" + func;
}
