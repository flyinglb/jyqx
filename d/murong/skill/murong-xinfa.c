// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("murong-xinfa", 1);
	
	if(me->query("gender") == "����" && lvl > 39)
		return notify_fail("�����һ�������������Ժ���ԭ����û������֮�����޷����Ľ���ķ��и���Ī��ı仯֮����\n");

	if(me->query("class") == "bonze" && lvl > 39)
		return notify_fail("������"+RANK_D->query_respect(me)
			+"������ţ���ôȴ��ѧϰĽ���ķ���\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("Ľ���ķ�ֻ�ܿ�ѧϰ����ߡ�\n");
}

