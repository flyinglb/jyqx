// guiyuan-tunafa.c ���ư� ��Ԫ���ɷ�
// zqb

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

//#include "force.h"

int valid_learn(object me)
{
	int i = (int)me->query_skill("kuihua-xinfa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;
	if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("��Ļ����ڹ�����㣬����ѧ��Ԫ���ɷ���\n");
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ��Ԫ���ɷ���ʲ�ᣡ\n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
//	|| me->query_skill("bibo-shengong",1)
//	|| me->query_skill("guiyuan-tunafa",1)
//	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huashan-neigong",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("shenyuan-gong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("wudu-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("xuantian-force",1)
//	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫ���ɷ�����\n");
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("��Ԫ���ŷ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"guiyuan-tunafa/" + func;
}

