// xiantian-qigong.c ��������
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("xiantian-qigong", 1);
        int t = 1, j;
        if (lvl<=100)
                for (j = 1; j < lvl / 10; j++)
                     t*=2;

        if ( me->query("gender") == "����")
                return notify_fail("���޸����ԣ��������������������������ڵ�����������\n");

        if ( me->query("class") == "bonze" )
                return notify_fail(RANK_D->query_respect(me)+"�����ҵ�����������������ȥ���˷��ţ�\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if(lvl<=100)
        {
                if (lvl > 10 && (int)me->query("shen") < t * 100)
                        return notify_fail("�����������̫���ˡ�\n");
        }
        else
        {
                if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000))
                        return notify_fail("�����������̫���ˡ�\n");
        }
	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("guiyuan-tunafa",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huashan-neigong",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
//	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
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
//	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1) )
              return notify_fail("�㲻��ɢ�˱����ڹ�������ѧϰ������������\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"xiantian-qigong/" + func;
}

