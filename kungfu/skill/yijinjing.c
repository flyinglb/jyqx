// yijinjing.c ���� �׽��
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
//		return notify_fail("��Ļ�Ԫһ��̫�ͣ��޷�ѧϰ�׽�񹦣�\n");
//       	if ( me->query("couple/have_couple") )
//		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ�׽�񹦣�\n");

//	if ( me->query("gender") != "����" && "Ů��" )
//		return notify_fail("����з�Ů֮�壬������ϰ�׽�񹦡�\n");

//	if ( nb < 100 && nb <= nh )
//		return notify_fail("��������ķ���Ϊ�������޷�����������׽�񹦡�\n");

//	if ( nf < 10)
//		return notify_fail("��Ļ����ڹ���򻹲������޷�����׽�񹦡�\n");

//	if ( ns > 0 ) 
//		return notify_fail("���ŷ�ɮ�����䣬�޷�����������׽�񹦡�\n");

	if (
	me->query_skill("kuihua-xinfa",1)
)
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�׽�񹦣���\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("�׽��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"yijinjing/" + func;
}
