// yijinjing.c 少林 易筋经神功
// Feb.21 1998 by Java

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
//        int i, nb, nf, oh, nh, ns, ts;
        int nb, nf, oh, nh, ns;
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	oh = (int)me->query_skill("hunyuan-yiqi", 1);
	nh = (int)me->query_skill("yijinjing", 1);
	ns = (int)me->query("guilty");

//        if ( oh < 100 )
//		return notify_fail("你的混元一气太低，无法学习易筋经神功！\n");
//       	if ( me->query("couple/have_couple") )
//		return notify_fail("你已经破了色戒，无法再学习易筋经神功！\n");

//	if ( me->query("gender") != "男性" && "女性" )
//		return notify_fail("你非男非女之体，不能练习易筋经神功。\n");

//	if ( nb < 100 && nb <= nh )
//		return notify_fail("你的禅宗心法修为不够，无法领会更高深的易筋经神功。\n");

//	if ( nf < 10)
//		return notify_fail("你的基本内功火候还不够，无法领会易筋经神功。\n");

//	if ( ns > 0 ) 
//		return notify_fail("你屡犯僧家数戒，无法领会更高深的易筋经神功。\n");

	if (
	me->query_skill("kuihua-xinfa",1)
)
		return notify_fail("你不先散了别派内功，怎能学易筋经神功？！\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("易筋经神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yijinjing/" + func;
}
