// bingxue-xinfa.c  冰雪心法
// By lucas

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	mapping skl;
	string *sname;
        skl = me->query_skills();
        sname = keys(skl);
        if ((int)me->query_skill("force", 1) < 10)
               return notify_fail("你的基本内功火候还不够，还不能学习冰雪心法。\n");

	 for (int i=0;i<sizeof(skl);i++){
	    if(sname[i] == "bingxue-xinfa") continue;
	    if(sname[i] == "huntian-qigong") continue;
	    if(sname[i] == "xuantian-force") continue;
	    if(sname[i] == "yijinjing") continue;
	    if(sname[i] == "yunlong-shengong") continue;
	    if(sname[i] == "taixuan-gong") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
                return notify_fail("你不先散了别派内功，怎能学冰雪心法？！\n");
         }

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("冰雪心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"bingxue-xinfa/" + func;
}


