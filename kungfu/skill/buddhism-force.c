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
    if ( me->query("gender") == "无性" )
        return notify_fail("你无根无性，阴阳不调，难以领会金刚不坏神功。\n");
    if ((int)me->query_skill("force", 1) < 1000)
        return notify_fail("你的基本内功火候还不够。\n");
    if ((int)me->query("unmarried") || (string)me->query("marry") )
	        return notify_fail("学金刚不坏神功必须是童子之身。\n");
	if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="jiuyang-shengong") continue;
        if (sname[i]=="taiji-shengong") continue;
        if (sname[i]=="yijing-force") continue;
		if (sname[i]=="buddhism-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("你不先散了别派内功，怎能学金刚不坏神功？！\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("金刚不坏神功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"buddhism-force/" + func;
}
