#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}


int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲������޷������Ԫ����\n");
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
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("shenlong-xinfa",1)
//	|| me->query_skill("shenyuan-gong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("wudu-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("xuantian-force",1)
//	|| me->query_skill("yijinjing",1)
//	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫ������\n");
	return 1;
}

int practice_skill(object me)
{
       return notify_fail("��Ԫ��ֻ��ͨ��ѧϰ�����������ȡ�\n");
              
}

string exert_function_file(string func)
{
        return __DIR__"shenyuan-gong/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIB + me->name()+"������������̬��Ϊ���ء�" NOR,
    "start_my_msg" : "������һվ��˫�ֻ���̧������һ������������ʼ��������ת��\n",
    "start_other_msg" : me->name()+"����������һվ��˫�ֻ���̧������ʼ�������������\n",
    "halt_msg" : "$Nüͷһ�壬�������������ַ���������\n",
    "end_my_msg" : "�㽫����������������������һȦ���������뵤������֣�������һ������\n",
    "end_other_msg" : "ֻ��"+me->name()+"���۾��������ϣ��������������ַ��£�������һ������\n"
          ]);
}

