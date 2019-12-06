// sunforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return "/daemon/skill/sunforce/" + func;
}

int protect(object me, object who, int damage_bonus)
{
	int protect_factor, count;

	protect_factor = me->query_skill("sunforce");

	if ( protect_factor	&& me->query("force") > 30
	&& random(protect_factor) > 10 ) {
		count = protect_factor + random(protect_factor);
		protect_factor = protect_factor * protect_factor /5;
		count += random(protect_factor);

		if( count >= damage_bonus )
			tell_object(me, "��ɹ������ù����񹦵Ļ������������˶Է����˺���\n"); 
		if( count >= damage_bonus/2 && count < damage_bonus )
			tell_object(me, "��ɹ������ù����񹦵Ļ������������˶Է��󲿷ֵ��˺���\n");                              
		if( count < damage_bonus/2 && count > 0 )
			tell_object(me, "��ɹ������ù����񹦵Ļ������������˶Է�һ���ֵ��˺���\n");                              

		me->add("force",-30);
	}

	return -count;
}
 
int enable_factor() { return 20; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 15; }