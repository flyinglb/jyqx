// kurong-changong.c ��������

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
    if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ���������������������Ŀ���������\n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("guiyuan-tunafa",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huashan-neigong",1)
	|| me->query_skill("huntian-qigong",1)
//	|| me->query_skill("hunyuan-yiqi",1)
//	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
//	|| me->query_skill("kurong-changong",1)
//	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("shenyuan-gong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("wudu-shengong",1)
//	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("xuantian-force",1)
//	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ������������\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"kurong-changong/" + func;
}


